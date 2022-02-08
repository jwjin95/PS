import sys

N, M = map(int, input().split())

arr = []


for _ in range(N):
    V, C, K = map(int, sys.stdin.readline().split())
    temp = 1
    tot = 0
    while temp + tot <= K:
        arr.append([V*temp, C*temp])
        tot += temp
        temp *= 2
    if K - tot:
        arr.append([V*(K-tot), C*(K-tot)])

arr.insert(0, [0,0])    
# dp = [[0]*(M+1)]*(len(arr)+1)
dp = [[0 for _ in range(M+1)] for _ in range(len(arr))]

# print(dp)

for i in range(1, len(arr)):
    for w in range(1, M+1):
        # print(i, w, dp[0])
        # dp[i][w] = max(dp[i][w], dp[i-1][w])
        # if w >= arr[i][0]:
        #     dp[i][w] = max(dp[i][w], dp[i-1][w-arr[i][0]]+arr[i][1])
            
        if w >= arr[i][0]:
            dp[i][w] = max(dp[i-1][w], dp[i-1][w-arr[i][0]]+arr[i][1])           
        else:
            dp[i][w] = dp[i-1][w]
           

print(dp[len(arr)-1][M])
# print(dp)
# print(dp[0])
# print(arr)