import sys

N = int(input())
M = int(input())
ans = 0
S = sys.stdin.readline()

Pn = 'I'
for _ in range(N):
    Pn += 'OI'

for i in range(M-2*N):
    if Pn == S[i:i+2*N+1]:
        ans += 1

print(ans)
