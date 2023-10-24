func isLucky(num string) bool {

	znac_map := map[string]int{
		"0": 0, "1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9,
	}

	right := num[3:]

	left := num[:3]

	result1 := 0

	result2 := 0

	for i := 0; i < 3; i++ {
		result1 = result1 + znac_map[string(right[i])]
		result2 = result2 + znac_map[string(left[i])]

	}
	return result1 == result2

}