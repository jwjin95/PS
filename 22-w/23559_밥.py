import sys

N, X = map(int, sys.stdin.readline().split())

arr = []
for _ in range(N):
    A, B = map(int, sys.stdin.readline().split())
    arr.append([A, B, A-B])

arr.sort(key = lambda x: x[2], reverse=True)

ans = 0
for i in range(N):
    if arr[i][2] <= 0:
        ans += arr[i][1]
        X -= 1000
    elif X >= (N-i) * 1000 + 4000:
        ans += arr[i][0]
        X -= 5000
    else:
        ans += arr[i][1]
        X -= 1000

print(ans)
