nonprime = [1, 1] + [0 for _ in range(2000000)]

for i in range(2, 2000000):
    if nonprime[i] == 0:
        for j in range(2*i, 2000000, i):
            nonprime[j] = 1

def isPalindrome(n):
    n = str(n)
    for i in range(len(n)//2):
        if n[i] != n[-1-i]:
            return False
    return True

N = int(input())

while True:
    if isPalindrome(N) and nonprime[N] == 0:
        print(N)
        break
    N += 1