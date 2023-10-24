package main

import (
	"fmt"
)

func data(n int) []int {

	var array []int
	count_word := 0

	for i := 0; i < n; i++ { // создаем функцию, в которой вводятся значения, а затем добавляются в массив

		fmt.Scan(&count_word)

		array = append(array, count_word)
	}

	return array

}
func aloneWord(num []int) int {
	mapp := make(map[int]int, 1)
	for _, elem := range num {

		mapp[elem]++ // создаем функцию, в которой создаем map и проверяем попарные элементы, если элемент в массиве остается без пары, возвращаем его

		if mapp[elem] == 2 {
			mapp[elem] = 0

		}

	}
	for _, elem := range num {
		if mapp[elem] == 1 {
			return elem
		}
	}

	return 0

}

func main() {

	var n int

	fmt.Scan(&n)

	numbers := data(n)

	fmt.Println(aloneWord(numbers))

}
