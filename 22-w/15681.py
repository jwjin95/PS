import sys
sys.setrecursionlimit(1e9+7)

N, R, Q = map(int, sys.stdin.readline().split())
adj_l = [[] for _ in range(N+1)]
dp = [1 for _ in range(N+1)]

for _ in range(N-1):
    U, V = map(int, sys.stdin.readline().split())
    adj_l[U].append(V)
    adj_l[V].append(U)

def dfs(node, par):

    for child in adj_l[node]:
        if child == par:
            continue

        dfs(child, node)
        dp[node] += dp[child]

dfs(R, 0)

for _ in range(Q):
    query = int(sys.stdin.readline())
    print(dp[query])