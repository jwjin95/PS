import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
area = []
dist = [[0 for _ in range(m)] for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]
q = deque()
dx = [1,-1,0,0]
dy = [0,0,1,-1]

for i in range(n):
    a = list(map(int, input().split()))
    if 2 in a:
        start = (i, a.index(2))
    area.append(a)

def bfs(x, y):
    visited[x][y] = True
    q.append((x,y))

    while(len(q) != 0):
        cur = q.popleft()
        for i in range(4):
            nx = cur[0] + dx[i]
            ny = cur[1] + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            if visited[nx][ny]:
                continue
            if area[nx][ny] == 0:
                continue
            visited[nx][ny] = True
            q.append((nx, ny))
            dist[nx][ny] = dist[cur[0]][cur[1]] + 1

bfs(start[0], start[1])

for i in range(n):
    for j in range(m):
        if dist[i][j] == 0 and area[i][j] == 1:
            dist[i][j] = -1

for i in range(n):
    for j in range(m):
        print(dist[i][j], end=' ')
    print()