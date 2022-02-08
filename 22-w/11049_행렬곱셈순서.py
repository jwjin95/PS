import sys

N = int(input())
INF = 2**31
matrix = []
dp = [[0 for _ in range(N)] for _ in range(N)]


for _ in range(N):
    r, c = map(int, sys.stdin.readline().split())
    matrix.append([r, c])

for i in range(N-1):
    dp[i][i+1] = matrix[i][0]*matrix[i][1]*matrix[i+1][1]

for i in range(1, N):
    for j in range(0, N-i):
        dp[j][j+i] = 2**31
        for k in range(j, j+i):
            dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + matrix[j][0]*matrix[k][1]*matrix[j+i][1])


print(dp[0][N-1])

