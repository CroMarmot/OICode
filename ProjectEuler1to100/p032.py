#!/usr/bin/env python3
a = 0
aset = set()
for i in range(2,100):
    ss = set()
    ii = i
    oki = True
    while ii != 0:
        if ii%10 in ss or ii%10 == 0:
            oki = False
            break
        ss.add(ii%10)
        ii//=10
    if not oki:
        continue
    for j in range(2,10000//i+1):
        s = set()
        ii = i
        oki = True
        while ii != 0:
            if ii%10 in s or ii%10 == 0:
                oki = False
                break
            s.add(ii%10)
            ii//=10

        jj = j
        okj = True
        while jj != 0:
            if jj%10 in s or jj%10 == 0:
                okj = False
                break
            s.add(jj%10)
            jj//=10
        if not okj:
            continue

        ij=i*j
        ok = True
        while ij != 0:
            if ij%10 in s or ij%10 == 0:
                ok = False
                break
            s.add(ij%10)
            ij//=10
        if not ok:
            continue

        if len(s) != 9:
            continue
        print(i,j,i*j)
        aset.add(i*j)

# HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
for v in aset:
    a+=v;
print(a)

