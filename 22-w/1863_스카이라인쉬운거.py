import sys

N = int(input())

arr = []
stack = []
ans = 0

for _ in range(N):
    x, y = map(int, sys.stdin.readline().split())
    arr.append([x,y])
arr.sort(key=lambda x: x[0])

for cor in arr:
    y = cor[1]
    while len(stack) != 0 and stack[-1] > y:
        stack.pop()
    if y != 0 and (len(stack) == 0 or stack[-1] < y):
        ans += 1
        stack.append(y)

print(ans)