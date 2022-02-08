import sys

N, K = map(int, sys.stdin.readline().split())

arr = []
for _ in range(N):
    x = int(sys.stdin.readline())
    arr.append(x)

left = 1
right = 2**31
mid = 0
k = K

while k != 0:
    if mid == (left + right) // 2:
        break

    mid = (left + right) // 2
    k = K
    for i in range(N):
        if arr[i] < mid:
            k -= mid - arr[i]
    if k < 0:
        right = mid - 1
    elif k > 0:
        left = mid + 1

print(mid)