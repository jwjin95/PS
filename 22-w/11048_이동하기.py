import sys

N, M = map(int, sys.stdin.readline().split())
c = []
dp = [[0 for _ in range(M)] for _ in range(N)]

for _ in range(N):
    l = list(map(int, sys.stdin.readline().split()))
    c.append(l)

dp[0][0] = c[0][0]

x = dp[0][0]
for i in range(1,N):
    x += c[i][0]
    dp[i][0] = x

x = dp[0][0]
for i in range(1, M):
    x += c[0][i]
    dp[0][i] = x

for i in range(1, N):
    for j in range(1, M):
        dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + c[i][j]

print(dp[N-1][M-1])