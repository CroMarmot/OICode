#!/usr/bin/env python3

N=100
# gcd == 1
def idx2v(idx):
    # print('idx',idx)
    if idx == 0:
        return 2
    if idx % 3 < 2:
        return 1
    return (idx//3+1)*2

fz,fm = 1,0
for i in range(0,N):
    # print(N-1-i)
    fz,fm = fm+fz*idx2v(N-1-i),fz

print(fz)
s=0
while fz !=0:
    s+=fz%10
    fz//=10
print(s)
