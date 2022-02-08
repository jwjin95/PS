from bisect import bisect_left, bisect_right

N = int(input())
L = list(map(int, input().split()))

M = int(input())
Q = list(map(int, input().split()))

ans = []
L.sort()

for num in Q:
    print(bisect_right(L, num) - bisect_left(L, num), end=' ')