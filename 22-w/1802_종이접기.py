import sys

T = int(sys.stdin.readline())

def dnc(le, s, l, r):
    
    if le == 1:
        return True
    elif le <= 3:
        if s[l] != s[r]:
            return True
        else:
            return False
    else:
        if dnc(le//2, s, l, (l+r)//2-1) and dnc(le//2, s, (l+r)//2+1, r):
            for i in range(le//2):
                if s[l+i] == s[r-i]:
                    return False
            return True
        return False

for _ in range(T):
    s = input()
    if dnc(len(s), s, 0, len(s)-1):
        print("YES")
    else:
        print("NO")