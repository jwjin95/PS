import sys

n = int(sys.stdin.readline())
data = list(map(int, sys.stdin.readline().split()))

list = sorted(list(set(data)))

dic = {list[i]:i for i in range(len(list))}

for i in range(len(data)):
    print(dic[data[i]], end= ' ')