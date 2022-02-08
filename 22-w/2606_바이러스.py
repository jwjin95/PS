import sys

input = sys.stdin.readline

N = int(input())
E = int(input())
adj = [[] for _ in range(N+1)]
visited = [False for _ in range(N+1)]
ans = 0

for _ in range(E):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

def dfs(node):
    global ans
    ans += 1
    visited[node] = True
    for nxt in adj[node]:
        if visited[nxt]:
            continue
        dfs(nxt)

dfs(1)

print(ans-1)