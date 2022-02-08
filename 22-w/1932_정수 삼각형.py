import sys

n = int(input())
l = []
dp = [[0 for _ in range(n)] for _ in range(n)]

for _ in range(n):
    temp = list(map(int, sys.stdin.readline().split()))
    l.append(temp)

dp[0][0] = l[0][0]

for i in range(n-1):
    for j in range(i+1):
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + l[i+1][j])
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + l[i+1][j+1])

print(max(dp[n-1]))
