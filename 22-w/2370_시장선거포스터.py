import sys
from bisect import bisect_left
input = sys.stdin.readline

pos = [0]*20010
ans = 0
arr = []
comp = []
srt = []

N = int(input())
for _ in range(N):
    l, r = map(int, input().split())
    arr.append([l,r])
    srt.append(l)
    srt.append(r)

srt.sort()
srt = list(set(srt))
for i in range(N):
    arr[i][0] = bisect_left(srt, arr[i][0])
    arr[i][1] = bisect_left(srt, arr[i][1])

for i in range(N):
    for j in range(arr[i][0], arr[i][1]+1):
        pos[j] = i+1

print(len(list(set(pos)))-1)