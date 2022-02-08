import sys

n = int(input())
l = list(map(int, sys.stdin.readline().split()))
ans = -1
in_list = [0 for i in range(2020203)]
checked = [False for i in range(2020203)]

for i in l:
    if in_list[i] == 0:
        in_list[i] += 1

for i in range(2):
    if in_list[i] == 0:
        print(i)
        sys.exit()

for i in range(2020202):
    if in_list[i] == 0:
        continue
    for j in range(2020202):
        if i*j>2020202:
            break
        if in_list[j] == 0:
            continue
        checked[i*j]=True

for i in range(2, 2020202):
    if checked[i]:
        continue
    ans = i
    break

print(ans)