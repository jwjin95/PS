import sys

N = int(input())
INF = 1e9
ans = INF
cost = []

dp = [[INF for _ in range(17)] for _ in range(1<<17)]

for _ in range(N):
    l = list(map(int, sys.stdin.readline().split()))
    cost.append(l)

for start in range(N):
    for i in range(1<<N):
        for j in range(N):
            dp[i][j] = INF
            
    dp[(1<<start)][start] = 0

    for i in range(1<<N):
        for j in range(N):
            if not (i & (1<<j)):
                continue

            for k in range(N):
                if not cost[j][k] or i & (1<<k):
                    continue
                x = i | (1<<k)
                dp[x][k] = min(dp[x][k], dp[i][j] + cost[j][k])
    
    for i in range(N):
        if cost[i][start]:
            ans = min(ans, dp[(1<<N)-1][i] + cost[i][start])

print(ans)