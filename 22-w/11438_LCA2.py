import sys
sys.setrecursionlimit(10**5)

N = int(sys.stdin.readline())
adj = [[] for _ in range(N+1)]
depth = [0 for _ in range(N+1)]
parent = [[0 for _ in range(21)] for _ in range(N+1)]


def dfs(node, par):
    depth[node] = depth[par]+1
    for nxt in adj[node]:
        if nxt == par:
            continue
        parent[nxt][0] = node
        dfs(nxt, node)

def lca(a, b):
    if depth[a] > depth[b]:
        a, b = b, a

    for i in range(20, -1, -1):
        if depth[b] - depth[a] >= 2**i:
            b = parent[b][i]

    if a == b:
        return a

    for i in range(20, -1, -1):
        if parent[a][i] != parent[b][i]:
            a = parent[a][i]
            b = parent[b][i]
    
    return parent[a][0]


for _ in range(N-1):
    a, b = map(int, sys.stdin.readline().split())
    adj[a].append(b)
    adj[b].append(a)

dfs(1, 0)
for j in range(1, 21):
    for i in range(1, N+1):
        parent[i][j] = parent[parent[i][j-1]][j-1]

M = int(sys.stdin.readline())

for _ in range(M):
    x, y = map(int, sys.stdin.readline().split())
    print(lca(x, y))