import sys

N = int(input())

for _ in range(N):
    w1, w2, w3 = sys.stdin.readline().split()

    dp = [[False for _ in range(len(w2)+1)] for _ in range(len(w1)+1)]
    dp[0][0] = True

    for i in range(1, len(w1)+1):
        if w1[i-1] == w3[i-1]:
            dp[i][0] = dp[i-1][0]
        else:
            dp[i][0] = False
    for i in range(1, len(w2)+1):
        if w2[i-1] == w3[i-1]:
            dp[0][i] = dp[0][i-1]
        else:
            dp[0][i] = False

    for i in range(1, len(w1)+1):
        for j in range(1, len(w2)+1):
            if w3[i+j-1] == w1[i-1] and w3[i+j-1] == w2[j-1]:
                dp[i][j] = dp[i-1][j] or dp[i][j-1]
            elif w3[i+j-1] == w2[j-1]:
                dp[i][j] = dp[i][j-1]
            elif w3[i+j-1] == w1[i-1]:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = False

    print("Data set "+ str(_+1) + ": ", end='')
    print("yes" if dp[len(w1)][len(w2)] else "no")