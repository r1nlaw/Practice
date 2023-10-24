package main

import (
	"fmt"
)

var input int

var schet5k int
var schet1k int
var schet500 int
var schet200 int
var schet100 int

func main() {

	fmt.Scan(&input)

	for input-5000 >= 0 {
		input = input - 5000
		schet5k++

	}
	for input-1000 >= 0 {
		input = input - 1000
		schet1k++
	}
	for input-500 >= 0 {
		input = input - 500
		schet500++
	}
	for input-200 >= 0 {
		input = input - 200
		schet200++
	}
	for input-100 >= 0 {
		input = input - 100
		schet100++
	}
	fmt.Println(schet5k, schet1k, schet500, schet200, schet100)
}
