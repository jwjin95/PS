import sys

N = int(input())

dp = [0 for _ in range(N+10)]

for i in range(N-1, -1, -1):
    for k in range(1, 7):
        dp[i] += 1/6*(1+dp[i+k])

print(dp[0])