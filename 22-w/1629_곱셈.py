A, B, C = map(int, input().split())

def dnc(n):
    if n == 1:
        return A
    half = dnc(n // 2)

    if n % 2 == 0:
        ret = half * half % C
    else:
        ret = (half * half) % C * A % C
    
    return ret

print(dnc(B)%C)