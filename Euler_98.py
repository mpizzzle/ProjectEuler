import sys
import math
import re
from sets import Set
from datetime import datetime

def find_all_anagrams(words):
    anagram_sets = []

    for word in words:
        word_is_anagram = False
        for anagram_set in anagram_sets:
            if sorted(str(word)) == sorted(str(anagram_set[0])):
                anagram_set.append(word)
                word_is_anagram = True
                break

        if not word_is_anagram:
            anagram_set = []
            anagram_set.append(word)
            anagram_sets.append(anagram_set)

    anagrams = []

    for anagram_set in anagram_sets:
        if len(anagram_set) > 1:
            anagrams.append(anagram_set)

    return anagrams

def match_anagrams_with_squares(anagram_sets, square_sets):

a = datetime.now()

with open('files/p098_words.txt') as f:
    words = re.split('","',f.read()[1:-1])

squares = []

for i in range(100000):
    if len(str(i**2)) == len(Set([c for c in str(i**2)])):
        squares.append(i**2)

match_anagrams_with_squares(find_all_anagrams(words), find_all_anagrams(squares))

delta = datetime.now() - a

print "total time: " + str(delta.total_seconds())
