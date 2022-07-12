#!/usr/bin/env python3

s={}
v={}
i=1
N=5 # this

def vorder(v):
    a = []
    while v != 0:
        a.append(v%10)
        v//=10
    a.sort()
    r = 0
    for i in range(len(a)):
        r*=10
        r+=a[len(a)-1-i]
    return r


while True:
    i+=1
    i3 = vorder(i**3)
    if i3 not in s :
        s[i3] = 0
        v[i3] = []
    s[i3]+=1
    v[i3].append(i)
    if s[i3] == N:
        print(v[i3][0]**3)
        print(v[i3])
        break
