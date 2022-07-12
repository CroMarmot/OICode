#!/usr/bin/env python3

answer = 0

for a in range(1,100):
    for b in range(1,100):
        v = a**b
        s = 0
        while v!=0:
            s+=v%10
            v//=10
        if s > answer:
            answer = s

print(answer)

