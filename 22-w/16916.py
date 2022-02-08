import sys

S = input()
P = input()

X = 1
MOD = 2**64
found = False
p_hash = 0
s_hash = 0

if len(P) > len(S):
    print(0)
    exit()

for i in range(len(P)-1, -1, -1):
    p_hash += (ord(P[i])-96)*X
    p_hash %= MOD
    X = (X * 27) % MOD

X = 1

for i in range(len(P)-1, -1, -1):
    s_hash += (ord(S[i])-96)*X
    s_hash %= MOD
    if i != 0:
        X *= 27
        X %= MOD

Xn = X

if s_hash == p_hash:
    print(1)
    found = True
    exit()

for i in range(len(S)-len(P)):
    
    s_hash -= (ord(S[i])-96)*Xn
    s_hash *= 27
    s_hash += (ord(S[i+len(P)])-96)
    s_hash %= MOD

    if s_hash == p_hash:
        print(1)
        found = True
        exit()



print(0)