package main

import (
	"fmt"
	"math"
)

type Item struct {
	i float64
}

func (a *Item) AddValue(v Item) {
	a.i += v.i
}

type Bread struct {
	name        string
	ingridience map[string]Item
	bake        baking
	weight      float64
}
type baking struct {
	bakeTime   int
	coolTime   int
	temprature int
}

type Baker interface {
	shoppingList(m1 map[string]Item) (m2 map[string]Item, m3 map[string]Item)
	ptintBakeInstructions()
	printBreadInfo()
}

func NewBread() *Bread {
	ingrideents := map[string]Item{"Whole Wheat flower": {500}, "yeast": {25},
		"salt": {25}, "sugar": {50}, "butter": {50}, "water": {350}}
	weight := 0.0
	for _, val := range ingrideents {
		weight += val.i
	}
	return &Bread{"Whole Wheat bread", ingrideents,
		baking{120, 60, 180}, weight}
}

func exists(ls []string, toCheck string) bool {
	for _, e := range ls {
		if e == toCheck {
			return true
		}
	}
	return false
}

func (b *Bread) shoppingList(available map[string]Item) (map[string]Item, map[string]Item) {
	avalib := make([]string, 0) //ingridience in avalible
	toBuy := make(map[string]Item)
	remain := make(map[string]Item)
	for k, _ := range available {
		avalib = append(avalib, k)
		val, prs := b.ingridience[k]
		if prs {
			//see if have  enough ingredients
			check := available[k].i - val.i
			if check > 0 {
				remain[k] = Item{check}
			} else {
				toBuy[k] = Item{math.Abs(check)}
			}
		} else {
			//not needed for bread so it is remainder
			remain[k] = available[k]
		}
	}
	for k, buy := range b.ingridience {
		if !exists(avalib, k) {
			toBuy[k] = buy
		}
	}
	return toBuy, remain
}

func (b *Bread) ptintBakeInstructions() {
	fmt.Println("Bake at ", b.bake.temprature, " Celsius for", b.bake.bakeTime,
		"minutes and let cool for ", b.bake.coolTime, " minutes.")
}

func (b *Bread) printBreadInfo() {
	fmt.Println(b.name)
	fmt.Println(b.ingridience)
	fmt.Println("Weight: ", b.weight/1000, "Kg")
}
func NewBreadVariation(name string, toAdd map[string]Item, remove map[string]Item) *Bread {
	dummyBread := NewBread()
	dummyBread.name = name
	for ka, va := range toAdd {
		val, prs := dummyBread.ingridience[ka]
		if !prs {
			dummyBread.ingridience[ka] = va
		} else {
			dummyBread.ingridience[ka] = Item{va.i + val.i}
		}
	}
	for kr, vr := range remove {
		val, prs := dummyBread.ingridience[kr]
		if !prs {
			fmt.Println("There is no element ", kr, ". It is not used in ingridients")
			continue
		} else {
			//assuming that if removing more than possible, than we remove element completly
			if val.i-vr.i <= 0 {
				delete(dummyBread.ingridience, kr)
			} else {
				dummyBread.ingridience[kr] = Item{val.i - vr.i}
			}

		}
	}
	weight := 0.0
	for _, val := range dummyBread.ingridience {
		weight += val.i
	}
	dummyBread.weight = weight
	return dummyBread
}

func main() {
	bk := make([]Baker, 2, 2)
	bk[0] = NewBread()
	bk[1] = NewBreadVariation("Sesame bread ", map[string]Item{"white flower": {200}, "sesame": {50}},
		map[string]Item{"Whole Wheat flower": {250}})
	bk[0].printBreadInfo()
	fmt.Println()
	bk[1].printBreadInfo()
	have := map[string]Item{"Whole Wheat flower": {5000}, "salt": {1000}, "sugar": {1000}, "a": {1}}

	//obtaining shopping list
	//for each element in bk []Baker use have map[string]Item, and decrement it
	//sum up all returned maps from every element
	shoppingList := make(map[string]Item, 0)
	for _, e := range bk {
		toBuy, remaining := e.shoppingList(have)
		have = remaining
		for k, v := range toBuy {
			vrem, psr := shoppingList[k]
			if !psr {
				shoppingList[k] = v
			} else {
				shoppingList[k] = Item{vrem.i + v.i}
			}
		}
	}
	fmt.Println()
	fmt.Println("Shopping List")
	fmt.Println(shoppingList)
	fmt.Println()
	fmt.Println("Baking instructions")
	for _, e := range bk{
		e.ptintBakeInstructions()
	}
}
