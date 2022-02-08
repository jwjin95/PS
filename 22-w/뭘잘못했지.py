N = int(input())

def whatIsRecursion(n):
    if n == 0:
        return
    print("____"*(N-n)+'도대체 내가 뭘 잘못했는데?')
    print("____"*(N-n)+'그걸 몰라서 물어?')
    print("____"*(N-n)+'뭘 잘못했는지 말해줘야 사과를 하든 말든 할거 아냐')
    print("____"*(N-n)+'그걸 말해줘야 알아?')
    print("____"*(N-n)+'관두자 관둬, 내가 말을 말아야지.')
    print("____"*(N-n)+'뭘 관둬? 지금 끝내자는 거야?')
    print("____"*(N-n+1)+'도대체 내가 뭘 잘못했는데?')
    whatIsRecursion(n-1)
    if n == 1:
        print("____"*(N)+'"됐어. 지금와서 말해봤자 뭐하겠어. 나 갈꺼야. 전화 하지마."')
        print("____"*(N)+'그래, 그만해')
    print("____"*(N-n)+'그래, 그만해')


whatIsRecursion(N)