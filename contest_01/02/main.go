package main

import (
	"fmt"
	"math"
)

func main() {
	var peopleuseo2 = 0.5
	var tree1createo2zagod = 20
	var tree2createo2zagod = 32

	var peopleusevgod = peopleuseo2 * 365

	fmt.Print(peopleusevgod, " ")

	fmt.Print(math.Ceil(peopleusevgod/float64(tree2createo2zagod)), " ")

	fmt.Print(math.Ceil(peopleusevgod/float64(tree1createo2zagod)), " ")

}