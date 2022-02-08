N, M = map(int, input().split())
ans = [0 for _ in range(N+1)]


def solve(level, num):
    if level == M:
        for i in range(M):
            print(ans[i], end=' ')
        print()

    for i in range(num, N+1):
       ans[level] = i
       solve(level+1, i+1) 

solve(0, 1)