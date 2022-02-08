import sys

N = int(input())
arr = list(map(int, sys.stdin.readline().split()))

arr.sort()

ans = 0
for i in range(N):
    ans += arr[i] * (N-i)

print(ans)