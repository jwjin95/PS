import sys

N = int(sys.stdin.readline())

for _ in range(N):
    flag_list = [0 for _ in range(26)]
    sentence = sys.stdin.readline()
    for i in range(len(sentence)):
        if 64 < ord(sentence[i]) < 91 or 96 < ord(sentence[i]) < 123:    
            if ord(sentence[i]) > 90:
                flag_list[ord(sentence[i])-97] = 1
            else:
                flag_list[ord(sentence[i])-65] = 1

    missing = ''
    for i in range(26):
        if flag_list[i] == 0:
            missing += chr(i+97)
    if missing != '':
        print("missing ", end='')
        print(missing)
    else:
        print("pangram")
