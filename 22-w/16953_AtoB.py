from collections import deque

A, B = map(int, input().split())
q = deque()

def bfs(x):
    q.append((x,1))

    while len(q) != 0:
        n = q.popleft()

        if n[0] == B:
            return n[1] 
        if n[0] > B:
            continue

        q.append((2*n[0], n[1]+1))
        q.append((10*n[0]+1, n[1]+1))

    return -1
    
print(bfs(A))
        