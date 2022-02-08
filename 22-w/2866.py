import sys

r, c = map(int, input().split())

count = 0
s = []
hash_val = [[0 for _ in range(c)] for _ in range(r)]
hash_x = 27
hash_modulo = 2**64

for i in range(r):
    s.append(input())

for i in range(c):
    hash_val[r-1][i] = ord(s[r-1][i])-96

for i in range(r-2, -1, -1):
    for j in range(c-1, -1, -1):
        hash_val[i][j] = hash_val[i+1][j] + (ord(s[i][j])-96) * (hash_x**(r-i-1))

for i in range(r-1):
    if len(list(set(hash_val[i+1]))) != len(hash_val[i+1]):
        break
    else:
        count += 1

print(count)