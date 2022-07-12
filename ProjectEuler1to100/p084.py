#!/usr/bin/env python3
import random
result = [0 for i in range(40)]
pos = 0
num = 0
limit = 1000000
N = 6
for i in range(0, limit):
    # 两枚4面体筛子
    # https://docs.python.org/3/library/random.html?highlight=randint#random.randint
    r1 = random.randint(1, N)
    r2 = random.randint(1, N)
    # 和
    pos += r1 + r2
    pos %= 40
    # Community Chest
    if pos == 2 or pos == 17 or pos == 33:
        r3 = random.randint(1, 16)
        if r3 == 1:
            pos = 0
        if r3 == 2:
            pos = 10
    # Chance
    if pos == 7 or pos == 22 or pos == 36:
        r4 = random.randint(1, 16)
        if r4 == 1:
            pos = 0
        if r4 == 2:
            pos = 10
        if r4 == 3:
            pos = 11
        if r4 == 4:
            pos = 24
        if r4 == 5:
            pos = 39
        if r4 == 6:
            pos = 5
        if r4 == 7 or r4 == 8:
            if pos == 7:
                pos = 12
            if pos == 22:
                pos = 25
            if pos == 36:
                pos = 5
        if r4 == 9:
            if pos == 7:
                pos = 12
            if pos == 22:
                pos = 28
            if pos == 36:
                pos = 12
        if r4 == 10:
            pos -= 3
    if pos == 30:
        pos = 10

    # 筛子是否相等
    if r1 == r2:
        num += 1
        if num == 3:
            pos = 10
            num = 0
    else:
        num = 0

    result[pos] += 1

for i in range(40):
    result[i] = (result[i]/limit, i)
result.sort()
for i in range(40):
    print(result[i])
