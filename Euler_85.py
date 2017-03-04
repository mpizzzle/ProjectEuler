import sys

def rectangles(x, y):
    return ((x * (x + 1)) * (y * (y + 1))) / 4

closest = 5000000
rec_x = 0
rec_y = 0

for x in range (0, 1000):
    for y in range (0, 1000):
        if y <= x:
            recs = rectangles(x, y)
            dif = abs(2000000 - recs)

            if dif < closest:
                closest = dif
                rec_x = x
                rec_y = y

print rec_x * rec_y
