#!/usr/bin/env python3

def f(v):
    d = v*((10**100)**2)
    l = 0;
    r = v*(10**100);
    while l+1<r :
        m = (l+r)//2;
        if m*m <= d:
            l = m
        else:
            r= m
    # print(l)
    if l%(10**100) == 0:
        return 0;
    ret = 0
    # if l%10 >= 5:
    #     ret += 1;
    l//=10;
    for i in range(0,100):
        ret+=l%10;
        l//=10;
    return ret


ans = 0;
for i in range(2,100):
    ans += f(i);
print(ans);













































