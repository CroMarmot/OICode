#!/usr/bin/env python3
a=2**1000;
s=0;
while(a>0):
    s+=a%10;
    a//=10;
print(s)
