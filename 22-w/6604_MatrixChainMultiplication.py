import sys

N = int(input())

mat = [[] for _ in range(30)]
for _ in range(N):
    M, r, c = sys.stdin.readline().split()
    r, c = int(r), int(c)
    mat[ord(M)-65] = [r,c]

while True:
    try:
        exp = sys.stdin.readline().rstrip()
        if exp == '':
            break


        ans = 0
        stack = []
        for i in range(len(exp)):
            if exp[i] == '(':
                stack.append('(')
            elif exp[i] == ')':
                b = stack.pop()
                a = stack.pop()

                if a[1] != b[0]:
                    ans = "error"
                    break
                stack.pop()
                ans += a[0]*a[1]*b[1]
                stack.append([a[0],b[1]])
            else:
                m = mat[ord(exp[i])-65]
                stack.append([m[0], m[1]])

        print(ans)

    except:
        exit()