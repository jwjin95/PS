import sys
sys.setrecursionlimit(2**20)

input = sys.stdin.readline

N , M = map(int, input().split())

adj = [[] for _ in range(2*N+1)]
dfsn = [0 for _ in range(2*N+1)]
sccn = [0 for _ in range(2*N+1)]
fin = [False for _ in range(2*N+1)]
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
        
        SCC.append(curSCC)
        SCCN += 1

    return ret

def rev(x):
    if x <= N:
        return x+N
    else:
        return x-N

for _ in range(M):
    a, b = map(int, input().split())
    if a < 0:
        a = abs(a) + N
    if b < 0:
        b = abs(b) + N
    adj[rev(a)].append(b)
    adj[rev(b)].append(a)


for i in range(1, 2*N+1):
    if dfsn[i] == 0:
        dfs(i)

for i in range(1, N+1):
    if sccn[i] == sccn[i+N]:
        print(0)
        exit()

print(1)
