A = input()
B = input()

dp = [[0 for _ in range(len(B)+1)] for _ in range(len(A)+1)]

for i in range(len(A)+1):
    for j in range(len(B)+1):
        if i == 0 or j == 0:
            continue
        if A[i-1] == B[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

print(dp[len(A)][len(B)])