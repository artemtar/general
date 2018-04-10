package main

import (
	"fmt"
	"math/rand"
	"math"
)

func RandomArray(len int) []float32 {
	array := make([]float32, len)
	for i := range array {
		array[i] = rand.Float32()
	}
	return array
}
func Process(a []float32, out chan float32) {
	ar := AbsDiff1(a[:len(a)/2], a[len(a)/2:])
	var sum float32
	sum = 0
	for _, val := range ar {
		sum = val + sum
	}
	out <- sum
}

func AbsDiff1(sliceA, sliceB []float32) []float32 {
	for i, val := range sliceA {
		sliceA[i] = float32(math.Abs(float64(val - sliceB[i])))
	}
	return sliceA
}

func main() {
	rand.Seed(100) // use this seed value
	out := make(chan float32, 1000)
	defer close(out)
	for i := 0; i < 1000; i++ {
		a := RandomArray(2 * (50 + rand.Intn(50)))
		go Process(a, out)
	}

	var sum float32
	sum = 0
	for j:= 0; j<1000; j++{
		sum = sum + <-out
	}
	fmt.Println(sum)
}
