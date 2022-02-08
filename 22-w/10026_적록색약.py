import sys
sys.setrecursionlimit(2**20)
input = sys.stdin.readline

N = int(input())
grid = []
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
visited = [[False for _ in range(N)] for _ in range(N)]
ans = 0
ans2 = 0

for _ in range(N):
    s = input().strip()
    grid.append(list(s))

def dfs(x, y):
    visited[x][y] = True
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if nx < 0 or ny < 0 or nx >= N or ny >= N:
            continue
        if visited[nx][ny]:
            continue
        if grid[x][y] != grid[nx][ny]:
            continue
        dfs(nx, ny)

for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            ans += 1
            dfs(i, j)

for i in range(N):
    for j in range(N):
        visited[i][j] = False
        if grid[i][j] == 'R':
            grid[i][j] = 'G'

for i in range(N):
    for j in range(N):
        if not visited[i][j]:
            ans2 += 1
            dfs(i, j)

print(ans, ans2)