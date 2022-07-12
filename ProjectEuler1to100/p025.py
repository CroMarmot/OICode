#!/usr/bin/env python3
f = [1,1]

def length(v):
    ret = 0
    while v != 0:
        ret+=1
        v//=10
    return ret

while True:
    f.append(f[-2]+f[-1])
    if length(f[-1]) == 1000:
        print(len(f))
        break
