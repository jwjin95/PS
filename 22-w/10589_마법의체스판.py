n, m = map(int, input().split())

ans = []

for i in range(2, n+1, 2):
    ans.append([i,1,i,m])
for i in range(2, m+1, 2):
    ans.append([1,i,n,i])

print(len(ans))
for item in ans:
    print(item[0],item[1],item[2],item[3])