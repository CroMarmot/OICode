#!/usr/bin/env python3
cost=[1,2,5,10,20,50,100,200]

def c(idx,l):
    if idx == 0:
        return 1
    ret = c(idx-1,l)
    while l >= cost[idx]:
        l-=cost[idx]
        ret+=c(idx-1,l)
    return ret

print(c(len(cost)-1,200))
