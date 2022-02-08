import sys
sys.setrecursionlimit(2**20)

input = sys.stdin.readline

V , E = map(int, input().split())

adj = [[] for _ in range(V+1)]
dfsn = [0 for _ in range(V+1)]
sccn = [0 for _ in range(V+1)]
fin = [False for _ in range(V+1)]
SCC = []
SCCN, cnt = 0, 0
stack = []


def dfs(x):
    global cnt, SCCN

    cnt += 1
    dfsn[x] = cnt
    stack.append(x)
    ret = dfsn[x]

    for nxt in adj[x]:
        if dfsn[nxt] == 0:
            ret = min(ret, dfs(nxt))
        elif fin[nxt] == 0:
            ret = min(ret, dfsn[nxt])

    if ret == dfsn[x]:
        curSCC = []
        while True:
            top = stack.pop()
            curSCC.append(top)
            fin[top] = True
            sccn[top] = SCCN
            if top == x:
                break
        curSCC.sort()
        SCC.append(curSCC)
        SCCN += 1

    return ret


for _ in range(E):
    a, b = map(int, input().split())
    adj[a].append(b)

for i in range(1, V+1):
    if dfsn[i] == 0:
        dfs(i)

SCC.sort(key=lambda x: x[0])

print(SCCN)
for comp in SCC:
    for v in comp:
        print(v, end=' ')
    print(-1)


