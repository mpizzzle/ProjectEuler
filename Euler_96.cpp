#include <array>
#include <fstream>
#include <sstream>
#include <unordered_set>

#include "Euler.h"

typedef std::array<std::array<int, 9>, 9> sudoku;
typedef std::unordered_set<int> set;

bool check(sudoku& bifurcation) {
    for (int i = 0; i < 9; ++i) {
        set h, v;

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
            set subgroup;

            for (int i = l * 3; i < (l * 3) + 3; ++i) {
                for (int j = k * 3; j < (k * 3) + 3; ++j) {
                    subgroup.insert(bifurcation[i][j]);
                }
            }

            if (subgroup.size() < 9) {
                return false;
            }
        }
    }

    return true;
}

void reset_hv(sudoku& puzzle, std::array<set, 9>& h, std::array<set, 9>& v) {
    for (int i = 0; i < 9; ++i) {
        h[i].clear();
        v[i].clear();

        for (int j = 0; j < 9; ++j) {
             h[i].insert(puzzle[i][j]);
             v[i].insert(puzzle[j][i]);
        }
    }
}

void reset_subgroup(sudoku& puzzle, set& s, set& m, int l, int k) {
    s.clear();
    m.clear();

    for (int i = l * 3; i < (l * 3) + 3; ++i) {
        for (int j = k * 3; j < (k * 3) + 3; ++j) {
            s.insert(puzzle[i][j]);
        }
    }

    for (int i = 1; i <= 9; ++i) {
        if (s.find(i) == s.end()) {
            m.insert(i);
        }
    }
}

void found(sudoku& puzzle, int x, int i, int j, int k, int l, bool r, bool vert, std::array<set, 9>& h, std::array<set, 9>& v, set& s, set& m) {
    puzzle[i][j] = x;
    r = true;
    vert = true;
    std::cout << "reduced i: " << i + 1 << ", j: " << j + 1 << " = " << x << std::endl;
    
    reset_hv(puzzle, h, v);
    reset_subgroup(puzzle, s, m, l, k);
}

sudoku reduce(sudoku puzzle) {
    bool reduced, vert = true;
    do {
        reduced = false;

        std::array<set, 9> h, v;

	reset_hv(puzzle, h, v);

        for (int l = 0; l < 3; ++l) {
            for (int k = 0; k < 3; ++k) {
                set missing, subgroup;
		reset_subgroup(puzzle, subgroup, missing, l, k);

                for (int i = l * 3; i < (l * 3) + 3; ++i) {
                    for (int j = k * 3; j < (k * 3) + 3; ++j) {
                        if (puzzle[i][j] <= 0) {
                            if (missing.size() == 1) {
                                found(puzzle, *missing.begin(), i, j, k, l, reduced, vert, h, v, subgroup, missing);
                                break;
                            }

                            set matches;

                            for (int x : missing) {
                                if (h[i].find(x) == h[i].end() && v[j].find(x) == v[j].end()) {
                                    matches.insert(x);
                                }
                            }

                            if (matches.size() == 1) {
                                found(puzzle, *matches.begin(), i, j, k, l, reduced, vert, h, v, subgroup, missing);
                                break;
                            }

                            for (int x : missing) {
                                if (subgroup.find(x) == subgroup.end()) {
                                    if (((puzzle[(l * 3) + ((i + 1) % 3)][j] > 0 && !vert)
                                    || h[(l * 3) + ((i + 1) % 3)].find(x) != h[(l * 3) + ((i + 1) % 3)].end())
                                    && ((puzzle[(l * 3) + ((i + 2) % 3)][j] > 0 && !vert)
                                    || h[(l * 3) + ((i + 2) % 3)].find(x) != h[(l * 3) + ((i + 2) % 3)].end())
                                    && ((puzzle[i][(k * 3) + ((j + 1) % 3)] > 0 && vert)
                                    || v[(k * 3) + ((j + 1) % 3)].find(x) != v[(k * 3) + ((j + 1) % 3)].end())
                                    && ((puzzle[i][(k * 3) + ((j + 2) % 3)] > 0 && vert)
                                    || v[(k * 3) + ((j + 2) % 3)].find(x) != v[(k * 3) + ((j + 2) % 3)].end())) {
                                        found(puzzle, x, i, j, k, l, reduced, vert, h, v, subgroup, missing);
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

    for (int j = 0; j < 5; ++j) {
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
