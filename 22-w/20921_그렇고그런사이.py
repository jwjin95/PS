N, K = map(int, input().split())

arr = [i for i in range(1, N+1)]

while K > 0:
    if arr[-1]-1 <= K:
        K -= arr[-1]-1
        arr.insert(-arr[-1]+1, arr.pop(-1))
    else:
        arr.insert(-K, arr.pop(-1))
        K = 0

for i in range(N):
    print(arr[i], end=' ')