#!/usr/bin/env python3
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def calc(i, p):
    sq = int(i**(0.5))
    if sq * sq == i:
        return (1, 0)

    hk = ((1, 0), (0, 1))
    # a, b, c => (a+b*sqrt{d})/c
    cur = (0, 1, 1)
    idx = 0
    while cur[0] == 0 or hk[0][0]*hk[0][0] - i*hk[0][1]*hk[0][1] != 1:
        if p:
            print("x_", idx, " = ", cur)
        z = int((cur[0] + cur[1] * (i**(0.5)))/cur[2])
        if p:
            print("a_", idx, " = ",  z)

        idx += 1
        # z 1
        # 1 0
        #    hk 00 01
        #       10 11
        newhk = (
            ((hk[0])[0]*z+(hk[1])[0], (hk[0])[1]*z+(hk[1])[1]),
            ((hk[0])[0], (hk[0])[1])
        )
        hk = newhk
        if p:
            print("hk = ", hk)
        a = cur[0]
        b = cur[1]
        c = cur[2]
        # c/(a+b*sqrt{i}-c*z)
        # c*(a-b*sqrt{i}-cz)/((a-cz)^2-b^2*i)
        nv = (c*(a-c*z), -c*b, (a-c*z)*(a-c*z)-b*b*i)
        cm = gcd(abs(nv[0]), abs(nv[1]))
        cm = gcd(cm, abs(nv[2]))
        nv = (nv[0]/cm, nv[1]/cm, nv[2]/cm)
        if nv[2] < 0:
            nv = (-nv[0], -nv[1], -nv[2])
        cur = nv
    return hk[0]


def main():
    ans = (0, (1, 0))
    for i in range(0, 1001):
        newans = calc(i, False)
        if newans[0] > ans[1][0]:
            ans = (i, newans[:])
        print(i, " -> ", newans)
    print(ans)


main()
