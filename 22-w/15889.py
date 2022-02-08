import sys

N = int(input())
pos = list(map(int, sys.stdin.readline().split()))
dst = max(pos)
ran = []
tup= []
rslt = False
max_range = 0

if N == 1:
    rslt = True
else:
    ran = list(map(int, sys.stdin.readline().split()))
    for i in range(len(ran)):
        tup.append((pos[i],ran[i]))
    tup.sort(key=lambda x:x[0])
    
    for i in range(len(tup)):
        if max_range < tup[i][0]:
            break
        if(max_range < tup[i][0]+tup[i][1]):
            max_range = tup[i][0]+tup[i][1]

    if max_range >= dst:
        rslt = True

if rslt:
    print("권병장님, 중대장님이 찾으십니다")
else:
    print("엄마 나 전역 늦어질 것 같아")