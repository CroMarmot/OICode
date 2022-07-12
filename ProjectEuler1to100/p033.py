#!/usr/bin/env python3
mi = 1
mj = 1


def gcd(v1,v2):
    if v2==0:
        return v1
    return gcd(v2,v1%v2)

for i in range(1,10):
    for j in range(1,10):
        for k in range(1,10):
            if j == k:
                continue

            # (i*10+k)/(k*10+j) = i/j
            if j*(i*10+k) == i*(k*10+j):
                print(i*10+k,k*10+j)
                mi*=i
                mj*=j

print(mj//gcd(mi,mj))


