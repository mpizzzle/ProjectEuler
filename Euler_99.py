import sys
import math
import re
from datetime import datetime

with open('files/p099_base_exp.txt') as f:
    pairs = f.read().splitlines()
    
line_number = 0
most_digits = 0.0

a = datetime.now()

for i, line in enumerate(pairs):
    base_exp = re.split(',',line)
    num_of_digits = float(base_exp[1]) * math.log10(float(base_exp[0]))
    
    if num_of_digits > most_digits:
        line_number = i + 1
        most_digits = num_of_digits

delta = datetime.now() - a

print line_number
print "total time: " + str(delta.total_seconds())