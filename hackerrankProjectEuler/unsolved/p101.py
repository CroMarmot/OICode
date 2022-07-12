arr = []
N = 0
X = []


def u(v):
    r = 0
    for i in range(0, N+1):
        r += X[i] * (v**i)
    return r


def gcd(a, b):
    if a < 0:
        return gcd(-a, b)
    if b < 0:
        return gcd(a, -b)
    if b == 0:
        return a
    return gcd(b, a % b)


def solve(arr, n):
    for i in range(0, n):
        for j in range(i+1, n):
            g = gcd(arr[i][i], arr[j][i])
            mul = arr[j][i] // g
            for idx in range(i, n+1):
                arr[j][idx] *= arr[i][i] // g
                arr[j][idx] -= arr[i][idx] * mul

    for ii in range(0, n):
        i = n-1-ii
        g = gcd(arr[i][i], arr[i][n])
        arr[i][i] //= g
        arr[i][n] //= g
        for j in range(0, i):
            g = gcd(arr[i][i], arr[j][i])
            mul = arr[j][i] // g
            for idx in range(0, n+1):
                arr[j][idx] *= arr[i][i] // g
                arr[j][idx] -= arr[i][idx] * mul

    # print('-----------------------------------')
    # print(arr)
    # print('-----------------------------------')
    r = []
    for i in range(0, n):
        r.append(arr[i][n])
    return r


def fitn(n):
    m = []
    for v in range(1, n+1):
        mr = []
        for mi in range(0, n):
            mr.append(v**mi)
        mr.append(u(v))
        m.append(mr)

    a = solve(m, n)
    r = 0
    for i in range(0, n):
        r += a[i] * ((n+1)**i)
    return r


def work():
    ans = 0
    for i in range(1, N+1):
        r = fitn(i)
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
