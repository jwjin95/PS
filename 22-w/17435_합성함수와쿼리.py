import sys

m = int(input())
f1 = list(map(int, sys.stdin.readline().split()))

fn = [[0 for _ in range(20)] for _ in range(m+10)]

for i in range(len(f1)):
    fn[i+1][0] = f1[i]

for j in range(1, 20):
    for i in range(1, m+1):
       fn[i][j] = fn[fn[i][j-1]][j-1]


def query(n, x):
    ans = x
    for i in range(19, -1, -1):
        if n >= 2**i:
            ans = fn[ans][i]
            n -= 2**i
    return ans


Q = int(input())
for _ in range(Q):
    n ,x = map(int, sys.stdin.readline().split())
    print(query(n, x))