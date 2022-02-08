import sys

T = int(sys.stdin.readline())
for _ in range(T):
    N = int(sys.stdin.readline())
    if N % 9 == 0 or N % 3 == 2:
        print("TAK")
    else:
        print("NIE")