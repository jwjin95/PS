import sys

N = int(input())
A = list(map(int, sys.stdin.readline().split()))

dp = [0 for _ in range(N+1)]

dp[0] = A[0]


for i in range(1, N):
    maximum = A[i]
    for j in range(i):
        if A[i] > A[j]:
            maximum = max(maximum, dp[j] + A[i])    
    dp[i] = maximum 

print(max(dp))