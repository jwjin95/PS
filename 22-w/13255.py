import sys

N = int(input())
K = int(input())
A = list(map(int, sys.stdin.readline().split()))

p = [N for _ in range(K+1)]

for i in range(K):
    p[i+1] = p[i]*(1-A[i]/N) + (N-p[i]) * (A[i]/N)

print(p[K])
