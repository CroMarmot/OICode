#!/usr/bin/env python3

def l(v):
    r = 0
    while v != 0:
        r+=1
        v//=10
    return r

a = 0
for i in range(1,10):
    for j in range(1,100):
        if l(i**j) == j:
            a+=1

print(a)



