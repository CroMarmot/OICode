#!/usr/bin/env python3
v = [1]

# 7

for i in range(1,10):
    v.append(v[-1]*i)
a=0
for i in range(10,10000000):
    s = 0
    ii = i
    while ii != 0:
        s += v[ii%10]
        ii//=10
    if s == i:
        print(s)
        a+=s

print(a)


