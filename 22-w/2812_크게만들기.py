N, K = map(int, input().split())
S = input()

stack = []

for i in range(len(S)):
    
    if K == 0 or len(stack) == 0 or (len(stack) != 0 and stack[-1] >= S[i]):
        stack.append(S[i])
        continue
    while len(stack) != 0 and stack[-1] < S[i]:
        if K == 0:
            break
        stack.pop()
        K -= 1
    stack.append(S[i])

for _ in range(K):
    stack.pop()

for n in stack:
    print(n, end='')