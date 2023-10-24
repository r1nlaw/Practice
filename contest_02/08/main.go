func reverse_line(line string) string {
	dlin_mass := len(line)
	reverse := ""
	for index := dlin_mass - 1; index >= 0; index-- { // Переворачиваем строку
		reverse += string(line[index])

	}
	return reverse
}

func isPalindrome(line string) bool {

	new_line_without_spess_zimbol := ""
	for key := range line {
		if 'A' <= line[key] && line[key] <= 'Z' {
			new_line_without_spess_zimbol += string(line[key]) // По таблице Аски говорим, что используем только буквы в верхнем и нижнем регистре
		}
		if 'a' <= line[key] && line[key] <= 'z' {
			new_line_without_spess_zimbol += string(line[key] - ' ') // Учитываем пробелы
		}

	}
	return new_line_without_spess_zimbol == reverse_line(new_line_without_spess_zimbol) // Сравниваем строку без спец символов с перевернутой строкой

}