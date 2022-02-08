import sys
sys.setrecursionlimit(2**20)
input = sys.stdin.readline

M, N, K = map(int, input().split())
dx = [1,-1,0,0]
dy  =[0,0,1,-1]
visited = [[False for _ in range(M)] for _ in range(N)]
ans_n = 0
ans_area = []
cnt = 0

def dfs(x, y, area):
    visited[x][y] = 1
    ret = area + 1
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if nx < 0 or ny < 0 or nx >= N or ny >= M:
            continue
        if visited[nx][ny]:
            continue
        ret = dfs(nx, ny, ret)

    return ret

for _ in range(K):
    x1, y1, x2, y2 = map(int, input().split())
    for i in range(x1, x2):
        for j in range(y1, y2):
            visited[i][j] = True

for i in range(N):
    for j in range(M):
        if not visited[i][j]:
            ans_n += 1
            ans_area.append(dfs(i, j, 0))

ans_area.sort()

print(ans_n)
for i in range(len(ans_area)):
    print(ans_area[i], end=' ')

