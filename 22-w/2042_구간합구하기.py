import sys

sys.setrecursionlimit(10**7)

def init(N, s, e):
    if s == e:
        tree[N] = arr[s]
        return tree[N]
    mid = (s + e) // 2
    tree[N] = init(2*N, s, mid) + init(2*N + 1, mid+1, e)
    return tree[N]

def query(N, s, e, l, r):
    if l > e or r < s:
        return 0
    if l <= s and e <= r:
        return tree[N]
    mid = (s + e) // 2
    return query(2*N, s, mid, l, r) + query(2*N + 1, mid+1, e, l, r)

def update(N, s, e, idx, num):
    if idx > e or idx < s:
        return
    if s == e:
        if idx == s:
            tree[N] = num
            return
    mid = (s + e) // 2
    update(2*N, s, mid, idx, num)
    update(2*N+1, mid+1, e, idx, num)
    tree[N] = tree[2*N] + tree[2*N+1]


N, M, K = map(int, sys.stdin.readline().split())

arr = []
tree = [0] * 3000000

for _ in range(N):
    arr.append(int(sys.stdin.readline()))

init(1, 0, N-1)

for _ in range(M+K):
    a, b, c = map(int, sys.stdin.readline().split())

    if a == 1:
        update(1, 0, N-1, b-1, c)
    elif a == 2:
        print(query(1, 0, N-1, b-1, c-1))