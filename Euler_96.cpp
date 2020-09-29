#include <array>
#include <fstream>
#include <sstream>
#include <unordered_set>

#include "Euler.h"

typedef std::array<std::array<int, 9>, 9> sudoku;

bool check(sudoku bifurcation) {
    for (int i = 0; i < 9; ++i) {
        std::unordered_set<int> horizontal_digits;
        std::unordered_set<int> vertical_digits;

        for (int j = 0; j < 9; ++j) {
             horizontal_digits.insert(bifurcation[i][j]);
             vertical_digits.insert(bifurcation[j][i]);
        }

        if (horizontal_digits.size() < 9 || vertical_digits.size() < 9) {
            return false;
        }
    }

    for (int l = 0; l < 3; ++l) {
        for (int k = 0; k < 3; ++k) {
            std::unordered_set<int> subgroup_digits;

            for (int i = l * 3; i < (l * 3) + 3; ++i) {
                for (int j = k * 3; j < (k * 3) + 3; ++j) {
                    subgroup_digits.insert(bifurcation[i][j]);
                }
            }

            if (subgroup_digits.size() < 9) {
                return false;
            }
        }
    }

    return true;
}

sudoku reduce(sudoku puzzle) {
    bool reduced;
    bool vert = true;
    do {
        reduced = false;

        std::array<std::unordered_set<int>, 9> horizontal_digits;
        std::array<std::unordered_set<int>, 9> vertical_digits;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                 horizontal_digits[i].insert(puzzle[i][j]);
                 vertical_digits[i].insert(puzzle[j][i]);
            }
        }

        for (int l = 0; l < 3; ++l) {
            for (int k = 0; k < 3; ++k) {
                std::unordered_set<int> missing_digits;
                std::unordered_set<int> subgroup_digits;

                for (int i = l * 3; i < (l * 3) + 3; ++i) {
                    for (int j = k * 3; j < (k * 3) + 3; ++j) {
                        subgroup_digits.insert(puzzle[i][j]);
                    }
                }

                for (int i = 1; i <= 9; ++i) {
                    if (subgroup_digits.find(i) == subgroup_digits.end()) {
                        missing_digits.insert(i);
                    }
                }


                if (missing_digits.size() > 0) {
                    for (int i = l * 3; i < (l * 3) + 3; ++i) {
                        for (int j = k * 3; j < (k * 3) + 3; ++j) {
                            if (puzzle[i][j] <= 0) {
                                if (missing_digits.size() == 1) {
                                    puzzle[i][j] = *missing_digits.begin();
                                    reduced = true;
                                    vert = true;
                                    std::cout << "reduced i: " << i + 1 << ", j: " << j + 1 << " = " << *missing_digits.begin() << std::endl;

                                    for (int q = 0; q < 9; ++q) {
                                        horizontal_digits[q].clear();
                                        vertical_digits[q].clear();

                                        for (int p = 0; p < 9; ++p) {
                                             horizontal_digits[q].insert(puzzle[q][p]);
                                             vertical_digits[q].insert(puzzle[p][q]);
                                        }
                                    }

                                    subgroup_digits.clear();
                                    for (int q = l * 3; q < (l * 3) + 3; ++q) {
                                        for (int p = k * 3; p < (k * 3) + 3; ++p) {
                                            subgroup_digits.insert(puzzle[q][p]);
                                        }
                                    }

                                    break;
                                }
                                if (missing_digits.size() <= 9) {
                                    std::unordered_set<int> matches;
                                    for (int x : missing_digits) {
                                        if (horizontal_digits[i].find(x) != horizontal_digits[i].end()) {
                                            matches.insert(x);
                                        }
                                        if (vertical_digits[j].find(x) != vertical_digits[j].end()) {
                                            matches.insert(x);
                                        }
                                    }

                                    std::unordered_set<int> match_matches;
                                    for (int x : missing_digits) {
                                        if (matches.find(x) == matches.end()) {
                                            match_matches.insert(x);
                                        }
                                    }

                                    if (match_matches.size() == 1) {
                                        puzzle[i][j] = *match_matches.begin();
                                        reduced = true;
                                        vert = true;
                                        std::cout << "reduced i: " << i + 1 << ", j: " << j + 1 << " = " << *match_matches.begin() << std::endl;

                                        for (int q = 0; q < 9; ++q) {
                                            horizontal_digits[q].clear();
                                            vertical_digits[q].clear();

                                            for (int p = 0; p < 9; ++p) {
                                                 horizontal_digits[q].insert(puzzle[q][p]);
                                                 vertical_digits[q].insert(puzzle[p][q]);
                                            }
                                        }

                                        subgroup_digits.clear();
                                        for (int q = l * 3; q < (l * 3) + 3; ++q) {
                                            for (int p = k * 3; p < (k * 3) + 3; ++p) {
                                                subgroup_digits.insert(puzzle[q][p]);
                                            }
                                        }

                                        break;
                                    }
                                }
                                for (int x : missing_digits) {
                                    if (subgroup_digits.find(x) == subgroup_digits.end()) {
                                        if (((puzzle[(l * 3) + ((i + 1) % 3)][j] > 0 && !vert)
                                        || horizontal_digits[(l * 3) + ((i + 1) % 3)].find(x) != horizontal_digits[(l * 3) + ((i + 1) % 3)].end())
                                        && ((puzzle[(l * 3) + ((i + 2) % 3)][j] > 0 && !vert)
                                        || horizontal_digits[(l * 3) + ((i + 2) % 3)].find(x) != horizontal_digits[(l * 3) + ((i + 2) % 3)].end())
                                        && ((puzzle[i][(k * 3) + ((j + 1) % 3)] > 0 && vert)
                                        || vertical_digits[(k * 3) + ((j + 1) % 3)].find(x) != vertical_digits[(k * 3) + ((j + 1) % 3)].end())
                                        && ((puzzle[i][(k * 3) + ((j + 2) % 3)] > 0 && vert)
                                        || vertical_digits[(k * 3) + ((j + 2) % 3)].find(x) != vertical_digits[(k * 3) + ((j + 2) % 3)].end())) {
                                            puzzle[i][j] = x;
                                            reduced = true;
                                            vert = true;
                                            std::cout << "reduced i: " << i + 1 << ", j: " << j + 1 << " = " << x << std::endl;

                                            for (int q = 0; q < 9; ++q) {
                                                horizontal_digits[q].clear();
                                                vertical_digits[q].clear();

                                                for (int p = 0; p < 9; ++p) {
                                                     horizontal_digits[q].insert(puzzle[q][p]);
                                                     vertical_digits[q].insert(puzzle[p][q]);
                                                }
                                            }

                                            subgroup_digits.clear();
                                            for (int q = l * 3; q < (l * 3) + 3; ++q) {
                                                for (int p = k * 3; p < (k * 3) + 3; ++p) {
                                                    subgroup_digits.insert(puzzle[q][p]);
                                                }
                                            }

                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (!reduced && vert) {
            vert = false;
            reduced = true;
        }
    } while (reduced);



    return puzzle;
}

sudoku bifurcate(sudoku bifurcation) {
    if (!check(bifurcation)) {
        sudoku blep = {};
        return blep;
    }

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (bifurcation[i][j] <= 0) {
                for (int k = 0; k < 9; ++k) {
                    bifurcation[i][j] = k + 1;

                    sudoku candidate = bifurcate(bifurcation);

                    if (check(candidate)) {
                        return candidate;
                    }
                }
            }
        }
    }

    return bifurcation;
}

void print(sudoku puzzle) {
    for (int k = 0; k < 9; ++k) {
        if (k % 3 == 0) {
            std::cout << "-------------------" << std::endl;
        }
        for (int l = 0; l < 9; ++l) {
            std::cout << ((l % 3 == 0) ? "|" : " ") << ((puzzle[k][l] < 0) ? 0 : puzzle[k][l]);
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "-------------------" << std::endl << std::endl;
}
int Euler::Sudoku()
{
    std::array<sudoku, 50> sudokus;
    std::ifstream file;
    std::string temp;
    int i = -1, j = 0, empty = 0, sum = 0;

    file.open("files/p096_sudoku.txt");

    while(std::getline(file, temp)) {
        if (temp[0] == 'G') {
            i++; j = 0; empty = 0; continue;
        }

        for (int k = 0; k < 9; ++k) {
            sudokus[i][j][k] = ((temp[k] - 48) != 0) ? temp[k] - 48 : empty--;
        }

        j++;
    }

    file.close();

    for (int j = 0; j < 50; ++j) {
        std::cout << "next puzzle " << j << ":" << std::endl;
        sudoku puzzle = sudokus[j];
        print(puzzle);
        sudoku reduced = reduce(puzzle);
        std::cout << "reduced:" << std::endl;
        print(reduced);
        sudoku solution = bifurcate(reduced);
        std::cout << "solution:" << std::endl;
        print(solution);
        std::stringstream ss;
        ss << solution[0][0] << solution[0][1] << solution[0][2];
        int temp;
        ss >> temp;
        sum += temp;

    }

    return sum;
}
