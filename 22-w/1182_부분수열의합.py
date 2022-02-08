N, S = map(int, input().split())

L = list(map(int, input().split()))

ans = 0
summation = 0

def solve(idx):
    global ans, summation
    if idx == N:
        return
    if summation + L[idx] == S:
        ans += 1
    
    solve(idx+1)
    summation += L[idx]
    solve(idx+1)
    summation -= L[idx]

solve(0)
print(ans)