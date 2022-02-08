import sys

N = int(input())
adj_list = [[] for _ in range(N+1)]
dp = [[0, 1] for _ in range(N+1)]

for _ in range(N-1):
    c1, c2 = map(int, sys.stdin.readline().split())
    adj_list[c1].append(c2)
    adj_list[c2].append(c1)

def dfs(node, par):

    for child in adj_list[node]:
        if child == par:
            continue
            
        dfs(child, node)
        dp[node][0] += max(dp[child][0], dp[child][1])
        dp[node][1] += dp[child][0]

dfs(1, 0)

ans = 0
for i in range(N+1):
    ans = max(ans, dp[i][0], dp[i][1])

print(ans)