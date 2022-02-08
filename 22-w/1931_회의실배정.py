import sys

N = int(input())

arr = []

for _ in range(N):
    s, e = map(int, sys.stdin.readline().split())
    arr.append([s, e])

arr.sort(key = lambda x: x[0])
arr.sort(key = lambda x: x[1])

ans = 0

temp = [0, 0]
for i in range(N):
    if arr[i][0] >= temp[1]:
        ans += 1
        temp = arr[i]

print(ans)
