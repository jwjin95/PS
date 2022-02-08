import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

N = int(input())
E = list(map(int, input().split()))
E.insert(0,0)
M = int(input())
checked = [False for _ in range(N+1)]
query = []
par = [0 for _ in range(N+1)]
A = [0 for _ in range(N+1)]
ans = []

def find(x):
    if par[x] == 0:
        return x
    par[x] = find(par[x])
    return par[x]

def merge(x, y):
    x, y = find(x), find(y)
    if x == y:
        return
    par[x] = y

for _ in range(M):
    a, b = map(int, input().split())
    if a == 2:
        checked[b] = True
    query.append([a,b])

for i in range(1, N+1):
    if checked[i] == True or E[i] == 0:
        continue
    if find(i) == find(E[i]):
        A[find(i)] = 1
    else:
        merge(i, E[i])

for _ in range(M):
    a, b = query[-1][0], query[-1][1]
    query.pop()
    if a == 1:
        if A[find(b)]:
            ans.append(-1)
        else:
            ans.append(find(b))
    else:
        if find(b) == find(E[b]):
            A[find(b)] = 1
        else:
            merge(b, E[b])

for _ in range(len(ans)):
    if ans[-1] < 0:
        print("CIKLUS")
    else:
        print(ans[-1])
    ans.pop()