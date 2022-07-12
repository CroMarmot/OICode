#!/usr/bin/env python3
# x*(x-1) / (y)*(y-1) = 1/2

# 8x^2-8x + 2 -1 = 4y^2-4y + 1


x = 1
y = 1

while True:
    x,y = 3*x+4*y,2*x+3*y;
    print(x,y);
    if (x+1)//2 > 1000000000000:
        print((y+1)//2)
        break

