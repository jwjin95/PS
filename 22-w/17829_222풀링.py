import sys

N = int(sys.stdin.readline())
arr = []

for _ in range(N):
    a = list(map(int, sys.stdin.readline().split()))
    arr.append(a)

def dnc(l, r_l, r_r, c_l, c_r):
    if l <= 2:
        part = [arr[r_l][c_l], arr[r_l][c_r], arr[r_r][c_l], arr[r_r][c_r]]
        # print("A", part)
        part.remove(max(part))
        return max(part)

    else:
        part = [dnc(l//2, r_l, (r_l+r_r)//2, c_l, (c_l+c_r)//2),
        dnc(l//2, (r_l+r_r)//2+1, r_r, c_l, (c_l+c_r)//2),
        dnc(l//2, r_l, (r_l+r_r)//2, (c_l+c_r)//2+1, c_r),
        dnc(l//2, (r_l+r_r)//2+1, r_r, (c_l+c_r)//2+1, c_r)]
        # print("B", part)
        part.remove(max(part))
        return max(part)

print(dnc(N,0,N-1,0,N-1))