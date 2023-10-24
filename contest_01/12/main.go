package main

import (
	"fmt"
)

var x int
var count int

func main() {
	fmt.Scan(&x)
	for x != 1 {
		if x%2 == 0 {
			x /= 2
			count++
		} else {
			x = x*3 + 1
			count++
		}
	}
	fmt.Print(count)

}
