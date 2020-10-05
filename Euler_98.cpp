#include "Euler.h" 
#include <algorithm>
#include <fstream>
#include <vector>
#include <unordered_map>

int anagrams_match(std::vector<std::string>& anagram_pair, std::vector<std::string>& anagram_squares) {
    int solution = -1;

    for (uint64_t i = 0; i < anagram_squares.size(); ++i) {
        std::unordered_map<char, char> char_map;
        bool match = true;

        for (uint64_t c = 0; c < anagram_pair[0].size(); ++c) {
            bool char_in_map = char_map.find(anagram_pair[0][c]) != char_map.end();

            for (std::pair<char, char> p : char_map) {
                if (p.second == anagram_squares[i][c] && ((p.first != anagram_pair[0][c]) || !char_in_map)) {
                    match = false;
                    break;
                }
            }

            if (match && !char_in_map) {
                char_map.insert(std::pair<char, char>(anagram_pair[0][c], anagram_squares[i][c]));
            }
        }

        if (match) {
            std::string built;

            for (uint64_t c = 0; c < anagram_pair[1].size(); ++c) {
                built.append(&char_map.find(anagram_pair[1][c])->second);
            }

            for (std::string anagram_square : anagram_squares) {
                if (built == anagram_square) {
                    solution = std::max(std::max(std::stoi(built), std::stoi(anagram_squares[i])), solution);
                }
            }
        }
    }

    return solution;
}

std::vector<std::vector<std::string> > find_all_anagrams(std::vector<std::string>& words) {
    std::vector<std::vector<std::string> > anagram_pairs;

    for (std::string& word : words) {
        bool word_is_anagram = false;

        for (std::vector<std::string>& anagram_pair : anagram_pairs) {
            std::string temp1 = word; std::sort(temp1.begin(), temp1.end());
            std::string temp2 = anagram_pair[0]; std::sort(temp2.begin(), temp2.end());

            if (temp1 == temp2) {
                word_is_anagram = true;
                anagram_pair.push_back(word);
                break;
            }
        }

        if (!word_is_anagram) {
            anagram_pairs.push_back(std::vector<std::string>({word}));
        }
    }

    return anagram_pairs;
}

int Euler::AnagramicSquares() {
    std::vector<std::string> words, squares;
    std::ifstream file;
    std::string temp;

    file.open("files/p098_words.txt");

    while(std::getline(file, temp, ',')) {
        temp.erase(temp.size() - 1, 1); temp.erase(0, 1);
        words.push_back(temp);
    }

    file.close();

    for (int i = 0; i < sqrt(1e9); ++i) {
        squares.push_back(std::to_string(i * i));
    }

    std::vector<std::vector<std::string> > anagram_pairs = find_all_anagrams(words);
    std::vector<std::vector<std::string> > anagram_squares = find_all_anagrams(squares);

    int largest_square = 0;

    for (std::vector<std::string>& anagram_pair : anagram_pairs) {
        for (std::vector<std::string>& anagram_square : anagram_squares) {
            if (anagram_square.size() > 1 && anagram_square[0].size() == anagram_pair[0].size() && anagram_pair.size() > 1) {
                int solution = anagrams_match(anagram_pair, anagram_square);
                if (solution > largest_square) {
                    largest_square = solution;
                }
            }
        }
    }

    return largest_square;
}
