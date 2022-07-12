def quick_p(b, p, mod):
    r = 1
    while p:
        if p % 2:
            r *= b
            r %= mod
        b *= b
        b %= mod
        p //= 2
    return r % mod


def is_prime_64(v):
    assert(v < 2**64)
    if v == 2:
        return True
    if v < 2:
        return False
    if v % 2 == 0:
        return False
    test_g = [2, 325, 9375, 28178, 450775, 9780504, 1795265022]
    startp = v-1
    while startp % 2 == 0:
        startp //= 2
    for i in range(len(test_g)):
        p = startp
        base = test_g[i]
        if base % v==0:
            continue
        find = False
        r = quick_p(base, p, v)
        while p != v-1:
            if r == v-1:
                find = True
                break
            #  -1 开始的序列, 或全1序列
            if r == 1:
                if p == startp:
                    find = True
                    break
                return False
            p *= 2
            r *= r
            r %= v
        if not find:
            return False
    return True


def main():
    print(is_prime_64(7))


main()
