#!/usr/bin/env python3
a=1;
for i in range(1,101):
    a*=i;
s=0;
while(a>0):
    s+=a%10;
    a//=10;
print(s)
