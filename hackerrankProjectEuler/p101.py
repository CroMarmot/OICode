N = 0
X = []
inv = []
po = []
poinv = []
MOD = 1000000007


def u(v):
    r = 0
    vi = 1
    for i in range(0, N+1):
        r += X[i] * vi
        r %= MOD
        vi *= v
        vi %= MOD
    return r


def init():
    # init inv
    global inv
    inv = []
    inv.append(0)
    inv.append(1)
    for i in range(2, N+10):
        inv.append(((MOD - MOD // i) * inv[MOD%i]) % MOD)
    # init power
    global po
    po = []
    po.append(1)
    for i in range(1, N+10):
        po.append( (po[i-1] * i) % MOD )

    global poinv
    poinv = []
    poinv.append(1)
    for i in range(1, N+10):
        poinv.append( (poinv[i-1] * inv[i]) % MOD )


def fitn(arr, n):
    r = 0
    for i in range(1, n+1):
        mul = arr[i-1]
        # 分子
        mul *= po[n] * inv[n+1-i]
        # 分母乘法逆元
        mul *= poinv[i-1] * poinv[n-i]
        if (n - i) % 2 == 1:
            mul *= -1
        mul %= MOD
        r += mul
        r %= MOD
    return (r+MOD)%MOD


def work():
    init()
    ans = 0
    arr = []
    for v in range(1, N+1):
        arr.append(u(v))

    for i in range(1, N+1):
        r = fitn(arr, i)
        print(r, end=' ')
        ans += r
    return ans


def pe():
    global N, X
    N = 10
    X = [1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1]
    print(work())


def main():
    global N, X
    N = int(input())
    X = list(map(int, input().split()))
    work()


# pe()
main()
