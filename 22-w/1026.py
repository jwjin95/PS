import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))
ans = 0

A.sort()
B.sort()

for i in range(N):
    ans += A[i] * B[N-i-1]

print(ans)