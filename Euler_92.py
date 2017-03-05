import sys

squares = [i * i for i in range(10)]
cache = [0] * 10000000
count = 0

def sum_digit_squares(n):
    s = 0
    while n:
        s += squares[n % 10]
        n //= 10
    return s

for n in range (1, 10000000):
    m = n

    while True:
        m = sum_digit_squares(m)

        if m == 1 or cache[m] == 1:
            cache[n] = 1
            break
        if m == 89 or cache[m] == 89:
            cache[n] = 89
            count += 1
            break
print count
