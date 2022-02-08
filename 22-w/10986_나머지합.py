import sys

N, M = map(int, sys.stdin.readline().split())

A = list(map(int, sys.stdin.readline().split()))

prefix = [0]*N
prefix[0] = A[0]%M
cnt = [0]*M

for i in range(1, N):
    prefix[i] = prefix[i-1] + A[i]
    prefix[i] %= M

for i in range(N):
    cnt[prefix[i]] += 1

ans = 0

for i in range(M):
    ans += cnt[i]*(cnt[i]-1)/2
ans += cnt[0]

print(int(ans))