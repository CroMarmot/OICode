#!/usr/bin/env python3


maxcnt = 0
maxp = 0

for p in range(3,1001):
    cnt = 0
    for a in range(1,p//3+1):
        for b in range(a,p-a+1):
            c = p-a-b;
            if c < b:
                break;

            if a*a+b*b == c*c:
                cnt+=1
    if cnt > maxcnt:
        maxcnt = cnt
        maxp = p
        print(cnt,p)

