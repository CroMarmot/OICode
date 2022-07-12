#!/usr/bin/env python3
a = 0
for i in range(2,300000):
    s = 0
    ii = i
    while ii !=0 :
        s+=(ii%10)**5
        ii//=10
    if s == i:
        a+=s
print(a)
