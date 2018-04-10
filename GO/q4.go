package main

import (
	"os"
	"log"
	"bufio"
	"strings"
	"strconv"
	"math"
	"sort"
	"fmt"
	"sync"
)
//output slice
var route []Route
//using this struct for output
type Route struct {
	node Edge
	dist float64
}
//node of graph
type Edge struct {
	name     string
	lat      float64
	lon      float64
	children []Edge
}

func angle(an float64) float64 {
	return an * math.Pi / 180
}

func distance(p Edge, c Edge) float64 {
	lat1 := angle(p.lat)
	lon1 := angle(p.lon)
	lat2 := angle(c.lat)
	lon2 := angle(c.lon)
	a := math.Sin((lat1 - lat2) / 2)
	b := math.Sin((lon1 - lon2) / 2)
	z := math.Cos(lat1) * math.Cos(lat2)
	return 2 * math.Asin(math.Sqrt(a*a+z*b*b)) * 6371
}
//building graph
func build(input []Edge) []Edge {
	//this part of the code makes root node of the graph
	//and next node of the graph, which is closes to root
	//and appends it into my graph
	graph := make([]Edge, 0)
	root := input[0] // first element is node
	graph = append(graph, root)
	input = input[1:]
	sort.Slice(input[:], func(j, k int) bool {
		return distance(input[j], root) < distance(input[k], root)
	})
	graph = append(graph, input[0])
	graph[0].children = append(graph[0].children, input[0])
	input = input[1:]

	sort.Slice(input[:], func(j, k int) bool {
		return input[j].lon < input[k].lon
	})
	//inserting rest of the nodes into graph
	for _, child := range input {
		closest := graph[0]
		dist := distance(closest, child)

		for _, parent := range graph {
			distance_check := distance(parent, child)
			if distance_check < dist {
				dist = distance_check
				closest = parent
			}
		}
		idx := 0
		for i, node := range graph {
			if node.name == closest.name {
				idx = i
			}
		}
		graph[idx].children = append(graph[idx].children, child)
		graph = append(graph, child)
	}
	return graph
}
//tracing algorithm.
//goes in depth of the tree first and than checks next child(width)
func trace(next Edge, graph []Edge) {
	route = append(route, Route{next, 0})
	check_children := find_children(next.name, graph)
	if len(check_children) == 0 {
		return
	}
	for _, node := range check_children {
		trace(node, graph)
	}
}
//looks for children of the node
func find_children(name string, graph []Edge) []Edge {
	for _, node := range graph {
		if name == node.name {
			return node.children
		}
	}
	return make([]Edge, 0)
}

//prepare for tracing and trace only on root of the tree
func trace_start(graph []Edge) {
	node := graph[0]
	route = append(route, Route{node, 0})
	check_children := find_children(node.name, graph)
	if len(check_children) == 0 {
		return
	}
	for _, node := range check_children {
		trace(node, graph)
	}
}
//saves solution into fulename
func saveRoute(route []Route, filename string) bool {
	file, err := os.Create(filename)
	if err != nil {
		log.Fatal("Cannot create file", err)
	}
	defer file.Close()
	for _, val := range route {
		fmt.Fprintln(file, val.node.name, " ", val.dist)
		fmt.Fprint(file, "\r\n")
	}
	return true
}
//helper fuction for concurrent part of assiment. See readme.txt
func worker(input_chan <-chan string, output_chan chan<- Edge, wg *sync.WaitGroup) {
	for {
		out, open := <-input_chan
		if !open {
			break
		}
		//build a node
		file_input := strings.Split(out, ",")
		lat, _ := strconv.ParseFloat(file_input[1], 64)
		lon, _ := strconv.ParseFloat(file_input[2], 64)
		output_chan <- Edge{file_input[0], lat, lon, make([]Edge, 0)}
	}
	wg.Done()
}
//creates an output slice
func findRoute(filename string, num int) {
	input := make([]Edge, 0)
	file, err := os.Open(filename)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)

	//concurrency, see readme.txt

	input_chan := make(chan string)
	output_chan := make(chan Edge)

	var wg sync.WaitGroup

	go func() {
		for scanner.Scan() {
			input_chan <- scanner.Text()
		}
		close(input_chan)
	}()
	for i := 0; i < num; i++ {
		wg.Add(1)
		go worker(input_chan, output_chan, &wg)
	}
	go func() {
		for j := range output_chan {
			input = append(input, j)
		}
	}()

	wg.Wait()

	//end concurrency
	sort.Slice(input[:], func(j, k int) bool {
		return input[j].lon < input[k].lon
	})
	graph := build(input)
	route = make([]Route, 0)
	trace_start(graph)
	comulative := 0.0
	for i := 1; i < len(route); i++ {
		comulative = comulative + distance(route[i].node, route[i-1].node)
		route[i].dist = comulative
	}
}

func main() {
	findRoute("input.txt", 4)
	saveRoute(route, "output.txt")
}