import sys

with open('files/p089_roman.txt') as f:
    numerals = f.read().splitlines()

characters = {'I': 1, 'V': 5, 'X': 10, 'L' : 50, 'C' : 100, 'D': 500, 'M': 1000}

digits   = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
tens     = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
hundreds = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']

columns = [digits, tens, hundreds]

chars_saved = 0

def numeral_to_int(n):
    vals = [characters[c] for c in reversed(n)]
    total = vals[0]

    for x in range (1, len(vals)):
        if vals[x] >= vals[x - 1]:
            total += vals[x]
        else:
            total -= vals[x]

    return total

def int_to_numeral(i):
    numeral = ''
    j = 0
    while i:
        if j < 3:
            numeral += columns[j][i % 10]
        else:
            numeral += 'M' * (i % 10)
        i //= 10
        j += 1
    return numeral

for n in numerals:
    chars_saved += len(n) - len(int_to_numeral(numeral_to_int(n)))

print chars_saved
