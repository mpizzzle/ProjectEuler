#include <array>
#include <fstream>
#include <sstream>
#include <unordered_set>

#include "Euler.h"

typedef std::array<std::array<int, 9>, 9> sudoku;

bool check(sudoku bifurcation) {
    for (int i = 0; i < 9; ++i) {
        std::unordered_set<int> h;
        std::unordered_set<int> v;

        for (int j = 0; j < 9; ++j) {
             h.insert(bifurcation[i][j]);
             v.insert(bifurcation[j][i]);
        }

        if (h.size() < 9 || v.size() < 9) {
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

void reset_hv(sudoku& puzzle, std::array<std::unordered_set<int>, 9>& h, std::array<std::unordered_set<int>, 9>& v) {
    for (int i = 0; i < 9; ++i) {
        h[i].clear();
        v[i].clear();

        for (int j = 0; j < 9; ++j) {
             h[i].insert(puzzle[i][j]);
             v[i].insert(puzzle[j][i]);
        }
    }
}

void reset_subgroup(sudoku& puzzle, std::unordered_set<int>& s, int l, int k) {
    s.clear();

    for (int i = l * 3; i < (l * 3) + 3; ++i) {
        for (int j = k * 3; j < (k * 3) + 3; ++j) {
            s.insert(puzzle[i][j]);
        }
    }
}

sudoku reduce(sudoku puzzle) {
    bool reduced;
    bool vert = true;
    do {
        reduced = false;

        std::array<std::unordered_set<int>, 9> h;
        std::array<std::unordered_set<int>, 9> v;

	reset_hv(puzzle, h, v);

        for (int l = 0; l < 3; ++l) {
            for (int k = 0; k < 3; ++k) {
                std::unordered_set<int> missing_digits;
                std::unordered_set<int> subgroup_digits;

		reset_subgroup(puzzle, subgroup_digits, l, k);

                for (int i = 1; i <= 9; ++i) {
                    if (subgroup_digits.find(i) == subgroup_digits.end()) {
                        missing_digits.insert(i);
                    }
                }


                for (int i = l * 3; i < (l * 3) + 3; ++i) {
                    for (int j = k * 3; j < (k * 3) + 3; ++j) {
                        if (puzzle[i][j] <= 0) {
                            if (missing_digits.size() == 1) {
                                puzzle[i][j] = *missing_digits.begin();
                                reduced = true;
                                vert = true;
                                std::cout << "reduced i: " << i + 1 << ", j: " << j + 1 << " = " << *missing_digits.begin() << std::endl;

	                        reset_hv(puzzle, h, v);
		                reset_subgroup(puzzle, subgroup_digits, l, k);

                                break;
                            }

                            std::unordered_set<int> matches;

                            for (int x : missing_digits) {
                                if (h[i].find(x) != h[i].end()) {
                                    matches.insert(x);
                                }

                                if (v[j].find(x) != v[j].end()) {
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

	                        reset_hv(puzzle, h, v);
		                reset_subgroup(puzzle, subgroup_digits, l, k);

                                break;
                            }
                            for (int x : missing_digits) {
                                if (subgroup_digits.find(x) == subgroup_digits.end()) {
                                    if (((puzzle[(l * 3) + ((i + 1) % 3)][j] > 0 && !vert)
                                    || h[(l * 3) + ((i + 1) % 3)].find(x) != h[(l * 3) + ((i + 1) % 3)].end())
                                    && ((puzzle[(l * 3) + ((i + 2) % 3)][j] > 0 && !vert)
                                    || h[(l * 3) + ((i + 2) % 3)].find(x) != h[(l * 3) + ((i + 2) % 3)].end())
                                    && ((puzzle[i][(k * 3) + ((j + 1) % 3)] > 0 && vert)
                                    || v[(k * 3) + ((j + 1) % 3)].find(x) != v[(k * 3) + ((j + 1) % 3)].end())
                                    && ((puzzle[i][(k * 3) + ((j + 2) % 3)] > 0 && vert)
                                    || v[(k * 3) + ((j + 2) % 3)].find(x) != v[(k * 3) + ((j + 2) % 3)].end())) {
                                        puzzle[i][j] = x;
                                        reduced = true;
                                        vert = true;
                                        std::cout << "reduced i: " << i + 1 << ", j: " << j + 1 << " = " << x << std::endl;

	                                reset_hv(puzzle, h, v);
		                        reset_subgroup(puzzle, subgroup_digits, l, k);

                                        break;
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
