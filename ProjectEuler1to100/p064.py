#!/usr/bin/env python3
"""
 (a sqrt(x)+b)/c
 xi =max{t| (ct-b)^2 <= a^2*x}
 a{i+1} = c a
 b{i+1} = -c(b-c x{i})
 c{i+1} = a^2 x - (b-c x{i})^2
"""
N = 10000 # change this
sq = 1

def gcd(v1,v2):
    if v2 == 0:
        return v1
    return gcd(v2,v1%v2)

# period
def getp(v):
    m = {}
    l = []
    a = 1
    b = 0
    c = 1
    idx = 0
    m[a] = {b:{c:idx}}
    while True:
        idx+=1
        xi = 1
        while (c*xi-b)**2 <= a**2*v:
            xi+=1
        xi-=1
        l.append(xi)

        na = c*a
        nb = -c*(b-c*xi)
        nc = a**2*v-(b-c*xi)**2
        gn = gcd(na,gcd(nb,nc))
        na//=gn
        nb//=gn
        nc//=gn
        if na in m:
            if nb in m[na]:
                if nc in m[na][nb]:
                    print(v,idx-m[na][nb][nc])
                    print(v,l)
                    return idx-m[na][nb][nc]
                else:
                    m[na][nb][nc] = idx
            else:
                m[na][nb] = {nc:idx}
        else:
            m[na]={nb:{nc:idx}}

        a,b,c=na,nb,nc

oddcnt = 0
for i in range(1,N+1):
    if i == sq**2:
        sq+=1
        continue
    if getp(i)%2==1:
        oddcnt+=1

print(oddcnt)
