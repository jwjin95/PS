import sys

N = int(input())

arr = []

for i in range(N):
    sentence = list(sys.stdin.readline().split())
    arr.append(sentence)

L = list(sys.stdin.readline().split())

for i in range(len(L)):
    for j in range(N):
        # print(i, j)
        if len(arr[j]) != 0 and len(L) != 0:
            if L[0] == arr[j][0]:
                del L[0]
                del arr[j][0]
                

empty = 0
for j in range(N):
    if len(arr[j]) == 0:
        empty += 1

if len(L) == 0 and empty == N:
    print("Possible")
else:
    print("Impossible")