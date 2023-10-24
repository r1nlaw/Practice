#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_can_exit_from_maze(vector<string>& mass_char, int row, int col, string moves = "", bool flag = true) {

    if (mass_char[row][col] == '#') {
        return false;
    }
    if (mass_char[row][col] == 'E') {
        return true;
    }
    else {
        if (moves == "up") {
            return is_can_exit_from_maze(mass_char, row + 1, col, "up") || is_can_exit_from_maze(mass_char, row, col - 1, "left") || is_can_exit_from_maze(mass_char, row, col + 1, "right");

        }
        else if (moves == "down") {
            return is_can_exit_from_maze(mass_char, row - 1, col, "down") || is_can_exit_from_maze(mass_char, row, col - 1, "left") || is_can_exit_from_maze(mass_char, row, col + 1, "right");

        }
        else if (moves == "right") {
            return is_can_exit_from_maze(mass_char, row, col + 1, "right") || is_can_exit_from_maze(mass_char, row + 1, col, "up") || is_can_exit_from_maze(mass_char, row - 1, col, "down");

        }
        else if (moves == "left") {
            return is_can_exit_from_maze(mass_char, row, col - 1, "left") || is_can_exit_from_maze(mass_char, row + 1, col, "up") || is_can_exit_from_maze(mass_char, row - 1, col, "down");

        }
        else {
            return is_can_exit_from_maze(mass_char, row, col - 1, "left") || is_can_exit_from_maze(mass_char, row, col + 1, "right") || is_can_exit_from_maze(mass_char, row + 1, col, "up") || is_can_exit_from_maze(mass_char, row - 1, col, "down");
        }

    }
}