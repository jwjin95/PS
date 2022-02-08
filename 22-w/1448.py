import sys

N = int(sys.stdin.readline())
l = []
ans = -1
for _ in range(N):
    n = int(sys.stdin.readline())
    l.append(n)

l.sort()
for i in range(N-2):
    if l[i] + l[i+1] > l[i+2]:
        ans = l[i] + l[i+1] + l[i+2]

print(ans)