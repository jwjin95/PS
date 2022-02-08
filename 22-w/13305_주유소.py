import sys

N = int(input())
dist = list(map(int, sys.stdin.readline().split()))
cost = list(map(int, sys.stdin.readline().split()))

inf = 2**32

ans = 0
dist_tmp = 0
cost_tmp = cost[0]
for i in range(1, N):
    if cost[i] < cost_tmp or i == N-1:
        dist_tmp += dist[i-1]
        ans += dist_tmp * cost_tmp
        cost_tmp = cost[i]
        dist_tmp = 0
    else:
        dist_tmp += dist[i-1]

print(ans)