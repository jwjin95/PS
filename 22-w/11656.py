import sys

S = input()
l = []
for i in range(len(S)):
    l.append(S[i:])

l.sort()

for word in l:
    print(word)