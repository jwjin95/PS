import sys, math

a, d = map(int, sys.stdin.readline().split())
N = int(sys.stdin.readline())

for _ in range(N):
    q, l, r  = map(int, sys.stdin.readline().split())
    if q == 1:
        ans = int((r-l+1)/2*(2*a+(l+r-2)*d))
    else:
        ans = math.gcd(a+(l-1)*d, d)
        if l == r:
            ans = a + (l-1)*d
    print(ans)