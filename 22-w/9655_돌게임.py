N = int(input())

dp = [False for _ in range(N+10)]
dp[1] = True
dp[2] = False
dp[3] = True

for i in range(4, N+1):
    if dp[i-1] == False or dp[i-3] == False:
        dp[i] = True
    else:
        dp[i] = False

if dp[N]:
    print("SK")
else:
    print("CY")