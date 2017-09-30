import sys
import math
import re
from sets import Set
from datetime import datetime

def find_unique_squares():
    square_sets = []
    square_is_anagram = False

    for i in range(100000):
        square = i**2

        if len(str(square)) == len(Set([c for c in str(square)])):
            for square_set in square_sets:
                if sorted(str(square)) == sorted(str(square_set[0])):
                    square_set.append(square)
                    square_is_anagram = True
                    break

            if not square_is_anagram:
                square_set = []
                square_set.append(square)
                square_sets.append(square_set)

            square_is_anagram = False

    squares = []

    for square_set in square_sets:
        if len(square_set) > 1:
            squares.append(square_set)

    return squares

def find_all_anagrams(words):
    anagram_sets = []
    word_is_anagram = False

    for word in words:
        for anagram_set in anagram_sets:
            if sorted(word) == sorted(anagram_set[0]):
                anagram_set.append(word)
                word_is_anagram = True
                break

        if not word_is_anagram:
            anagram_set = []
            anagram_set.append(word)
            anagram_sets.append(anagram_set)

        word_is_anagram = False

    anagrams = []

    for anagram_set in anagram_sets:
        if len(anagram_set) > 1:
            anagrams.append(anagram_set)

    return anagrams

with open('files/p098_words.txt') as f:
    words = re.split('","',f.read()[1:-1])

a = datetime.now()

anagram_sets = find_all_anagrams(words)
square_sets  = find_unique_squares()

delta = datetime.now() - a

print "total time: " + str(delta.total_seconds())
