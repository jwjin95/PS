import sys

N = int(input())
l = list(map(int, sys.stdin.readline().split()))
dp = [0 for _ in range(N)]

for i in range(N):
    maximum = 0
    for j in range(i):
        if l[i] > l[j]:
            maximum = max(maximum, dp[j])
    dp[i] = maximum + 1

print(max(dp))