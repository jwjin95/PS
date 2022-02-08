import sys
from collections import deque

N = int(sys.stdin.readline())

A = list(map(int, sys.stdin.readline().split()))

ans = deque()
for i in range(N-1, -1, -1):
    if A[i] == 1:
        ans.appendleft(N-i)
    elif A[i] == 2:
        ans.insert(1, N-i)
    elif A[i] == 3:
        ans.append(N-i)
    
for n in ans:
    print(n, end=' ')