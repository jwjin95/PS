import sys



n = int(input())
A = list(map(int, sys.stdin.readline().split()))
m = int(input())

tree = [0] * 300000


def query(N, s, e, i, j, k):
    if i > e or j < s:
        return
    # if s == e:
    if i <= s and e <= j:
        tree[N] += k    
        return

    # if s <= i and j <= e:
    #     tree[N] += k
    #     if s == e:
    #         return
    mid = (s + e) // 2
    query(2*N, s, mid, i, j, k)
    query(2*N+1, mid+1, e, i, j, k)
    return

def find(N, s, e, x):
    global ans
    ans += tree[N]
    if s == e:
        return ans
        # if s == x:
        #     return tree[N]
    
    mid = (s + e) // 2
    if s <= x <= mid:
        return find(2*N, s, mid, x)
    elif mid+1 <= x <= e:
        return find(2*N+1, mid+1, e, x)

for _ in range(m):
    l = list(map(int, sys.stdin.readline().split()))
    
    if l[0] == 1:
        query(1, 0, n-1, l[1]-1, l[2]-1, l[3])
    else:
        ans = 0
        print(find(1, 0, n-1, l[1]-1) + A[l[1]-1])
