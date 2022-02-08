import sys

n, m = map(int, input().split())

arr = []
tree = [[]]*300000
inf = 2**64

for _ in range(n):
    arr.append(int(sys.stdin.readline()))

def init(N, s, e):
    if s == e:
        tree[N] = [arr[s], arr[s]]
        return tree[N]

    mid = (s + e) // 2
    init_l = init(2*N, s, mid)
    init_r = init(2*N+1, mid+1, e)
    maximum = max(init_l[1], init_r[1])
    minimum = min(init_l[0], init_r[0])

    tree[N] = [minimum, maximum]

    return tree[N]

def query(N, s, e, l, r):
    if r < s or l > e:
        return [inf, 0]
    if l <= s and e <= r:
        return tree[N]
    
    mid = (s + e) // 2
    query_l = query(2*N, s, mid, l, r)
    query_r = query(2*N+1, mid+1, e, l, r)
    
    minimum = min(query_l[0], query_r[0])
    maximum = max(query_l[1], query_r[1])

    return [minimum, maximum]

init(1, 0, n-1)

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    result = query(1, 0, n-1, a-1,b-1)
    print(result[0], result[1])