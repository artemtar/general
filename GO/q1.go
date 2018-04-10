package main

import (
	"fmt"
	"bufio"
	"os"
	"errors"
	"strings"
	"strconv"
	"math"
)

func checkinput(s string) bool {
	if s == "1" || s == "-1" || s == "0" {
		return false
	} else {
		return true
	}
}

func main() {
	reader := bufio.NewScanner(os.Stdin)
	prevSlice := make([]float32, 0)
	prevSlice = append(prevSlice, 0)
	check := false

	fmt.Println("Select version: ")
	reader.Scan()
	version := reader.Text()
	for checkinput(version) {
		fmt.Println("Incorrect input, please repeat: ")
		reader.Scan()
		version = reader.Text()
	}

	for {
		var inputSlice []float32
		fmt.Print("Previous slice: ")
		fmt.Println(prevSlice)
		fmt.Println("Enter another slice of floating point numbers " +
			"(Anything else to end slice)")
		reader.Scan()
		input := reader.Text()
		//input into inputSlice
		arStr := strings.Split(input, " ")
		for _, val := range arStr {
			i, err := strconv.ParseFloat(val, 32)
			if err != nil {
				fmt.Println("Cannot convert ", val, " into number")
				check = true
				break
			}
			inputSlice = append(inputSlice, float32(i))
		}
		if check {
			break
		}
		ver, _ := strconv.Atoi(version)
		res, err := AbsDiff(prevSlice, inputSlice, ver)
		if err != nil {
			fmt.Println(err.Error())
			fmt.Println("q to quit (Anything else to continue): ")
			prevSlice = inputSlice
			reader.Scan()
			input = reader.Text()
			if input == "q" {
				break
			}
		} else {
			fmt.Println("Result: ", res)
			prevSlice = make([]float32, len(inputSlice))
			copy(prevSlice, inputSlice)
			fmt.Println("q to quit (Anything else to continue): ")
			reader.Scan()
			input = reader.Text()
			if input == "q" {
				break
			}
		}
	}
}

func AbsDiff(sliceA, sliceB []float32, version int) ([]float32, error) {
	switch version {
	case 0:
		{
			if len(sliceA) != len(sliceB) {
				return nil, errors.New("slices are not the same length")
			} else {
				for i, val := range sliceA {
					sliceA[i] = float32(math.Abs(float64(val - sliceB[i])))
				}
				return sliceA, nil
			}
		}
	case -1:
		{
			retSlice := make([]float32, 0)
			if len(sliceA) > len(sliceB) {
				j := 0
				for i, val := range sliceB {
					retSlice = append(retSlice, float32(math.Abs(float64(sliceA[i]-val))))
					j = i
				}
				for z := j + 1; z < len(sliceA); z++ {
					retSlice = append(retSlice, float32(math.Abs(float64(sliceA[z]))))
				}
			} else {
				n := 0
				for i, val := range sliceA {
					retSlice = append(retSlice, float32(math.Abs(float64(val-sliceB[i]))))
					n = i
				}
				for z := n + 1; z < len(sliceB); z++ {
					retSlice = append(retSlice, float32(math.Abs(float64(sliceB[z]))))
				}
			}
			return retSlice, nil
		}
	case 1:
		{
			retSlice := make([]float32, 0)
			if len(sliceA) > len(sliceB) {
				for i, val := range sliceB {
					retSlice = append(retSlice, float32(math.Abs(float64(sliceA[i]-val))))
				}
			} else {
				for i, val := range sliceA {
					retSlice = append(retSlice, float32(math.Abs(float64(val-sliceB[i]))))
				}
			}
			return retSlice, nil
		}
	}
	return nil, nil
}
