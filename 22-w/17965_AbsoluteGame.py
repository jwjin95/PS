import sys

N = int(input())

A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

A.sort()
B.sort()

ans = -1e12

for i in range(N):
    a = 1e12
    for j in range(N):
        a = min(a, abs(A[i]-B[j]))
    ans = max(ans, a)

print(ans)