func shift(mass []int, steps int) {

	mass_copy := make([]int, len(mass))

	copy(mass_copy, mass)

	if steps < 0 {
		steps = 10 - steps*(-1)%10
	}
	for index_mass := 0; index_mass < steps%10; index_mass++ {

		mass[index_mass] = mass_copy[10-steps%10+index_mass]
	}

	for index_mass := steps % 10; index_mass < 10; index_mass++ {

		mass[index_mass] = mass_copy[index_mass-steps%10]
	}

}