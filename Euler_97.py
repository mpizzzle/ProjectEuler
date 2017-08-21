import sys
import math
from datetime import datetime

def find_last_x_digits(base, exponent, x):
	mod = 10 ** x
	exp = 1
	squares = []
	squares.append(base % mod)
	result = 1
	
	while exp < exponent:
		squares.append((squares[-1] ** 2) % mod)
		exp = exp * 2
	
	for i in range(len(squares)):
		if (2 ** i) & exponent:
			result = (result * squares[i]) % mod
		
	return result

base = 2
exponent = 7830457
x = 10

a = datetime.now()
result = ((find_last_x_digits(base, exponent, x) * 28433) + 1) % (10 ** x)
c = datetime.now() - a

print result
print "total time: " + str(c.total_seconds())

print find_last_x_digits(7777777, 7777777, 5)