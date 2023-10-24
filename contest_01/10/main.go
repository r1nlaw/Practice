package main

import (
	"fmt"
)

func main() {
	var canswim string
	var canfly string
	var longneck string

	fmt.Scan(&canswim, &canfly, &longneck)

	if canswim == "Нет" && canfly == "Нет" && longneck == "Нет" {
		fmt.Print("Кот")
	}
	if canswim == "Нет" && canfly == "Нет" && longneck == "Да" {
		fmt.Print("Жираф")
	}
	if canswim == "Нет" && canfly == "Да" && longneck == "Нет" {
		fmt.Print("Курица")
	}
	if canswim == "Нет" && canfly == "Да" && longneck == "Да" {
		fmt.Print("Страус")
	}
	if canswim == "Да" && canfly == "Нет" && longneck == "Нет" {
		fmt.Print("Дельфин")
	}
	if canswim == "Да" && canfly == "Нет" && longneck == "Да" {
		fmt.Print("Плезиозавры")
	}
	if canswim == "Да" && canfly == "Да" && longneck == "Нет" {
		fmt.Print("Пингвин")
	}
	if canswim == "Да" && canfly == "Да" && longneck == "Да" {
		fmt.Print("Утка")
	}

}
