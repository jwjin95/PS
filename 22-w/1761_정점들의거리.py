import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

LENGTH = 17
N = int(input())
depth = [0 for _ in range(N+1)]
parent = [[0 for _ in range(LENGTH)] for _ in range(N+1)]
dist = [[0 for _ in range(LENGTH)] for _ in range(N+1)]
adj = [[] for _ in range(N+1)]

def dfs(node, par, d):
    depth[node] = depth[par]+1
    parent[node][0] = par
    dist[node][0] = d
    for nxt in adj[node]:
        if nxt[0] == par:
            continue
        # parent[nxt[0]][0] = node
        # dist[nxt[0]][0] = nxt[1]
        dfs(nxt[0], node, nxt[1])

def lca(x, y):
    ans = 0
    if depth[x] > depth[y]:
        x, y = y, x
    for i in range(LENGTH-1, -1, -1):
        if depth[y] - depth[x] >= 2**i:
            ans += dist[y][i]
            y = parent[y][i]

    if x == y:
        return ans
    
    for i in range(LENGTH-1, -1, -1):
        if parent[x][i] != parent[y][i]:
            ans += dist[x][i] + dist[y][i]
            x = parent[x][i]
            y = parent[y][i]
    
    ans += dist[x][0] + dist[y][0]
    return ans
    
for _ in range(N-1):
    a, b, d = map(int, input().split())
    adj[a].append([b,d])
    adj[b].append([a,d])

dfs(1, 0, 0)

for j in range(1, LENGTH):
    for i in range(1, N+1):
        parent[i][j] = parent[parent[i][j-1]][j-1]
        dist[i][j] = dist[i][j-1] + dist[parent[i][j-1]][j-1]

M = int(input())
for _ in range(M):
    a, b = map(int, input().split())
    print(lca(a, b))