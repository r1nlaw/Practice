package main

import (
	"fmt"
)

func main() {
	var a int
	var b int
	var c int
	var temp_max int

	fmt.Scan(&a, &b, &c)

	if a > b {
		temp_max = a
	} else {
		temp_max = b
	}
	if temp_max > c {
		fmt.Print(temp_max)
	} else {
		fmt.Print(c)
	}

}
