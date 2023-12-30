package main

import "fmt"

type Human struct {
	name string
	age  int
}

func printTypes(data []interface{}) { // Функция printTypes для вывода статического типа каждого элемента в слайсе data
	for _, val := range data { // Итерация по каждому элементу в слайсе data
		switch val.(type) { // Определение типа элемента с помощью оператора switch
		case int:
			fmt.Printf("int ")
		case string:
			fmt.Printf("string ")
		case Human:
			fmt.Printf("Human ")
		case *Human:
			fmt.Printf("*Human ")
		default:
			fmt.Printf("interface ")
		}
	}
}

func main() {
	var count int
	fmt.Scan(&count)

	var data []interface{} = make([]interface{}, count)
	for i := 0; i < count; i++ {
		var t string
		fmt.Scan(&t)
		switch t {
		case "int":
			var val int = 0
			data[i] = interface{}(val)
		case "string":
			var val string = "0"
			data[i] = interface{}(val)
		case "Human":
			var val Human = Human{}
			data[i] = interface{}(val)
		case "*Human":
			var val *Human = &Human{}
			data[i] = interface{}(val)
		}
	}

	printTypes(data)
}
