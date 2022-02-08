import sys

T = int(input())


for _ in range(T):
    found = False
    words = []
    k = int(sys.stdin.readline())
    for _ in range(k):
        w = sys.stdin.readline().strip()
        words.append(w)
    
    for i in range(k-1):
        for j in range(i+1, k):
            cand1 = words[i] + words[j]
            cand2 = words[j] + words[i]

            if cand1 == cand1[::-1]:
                found = True
                print(cand1)
                break
            elif cand2 == cand2[::-1]:
                found = True
                print(cand2)
                break        
        if found:
            break
    if not found:
        print("0")
