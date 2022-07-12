#!/usr/bin/env python3
import re
def run():
    filename = './p089_roman.txt'
    file = open(filename)
    ans = 0
    for line in file:
        a = len(line)
        # 最多4个
        line = re.sub('IIII','IV',line)
        line = re.sub('VIV','IX',line)

        line = re.sub('XXXX','XL',line)
        line = re.sub('LXL','XC',line)

        line = re.sub('CCCC','CD',line)
        line = re.sub('DCD','CM',line)
        b = len(line)
        ans += a -b
    print(ans)
# 743
run()
