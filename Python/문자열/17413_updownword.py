import sys
input = sys.stdin.readline
S = input()
lst = S.split('>')

def splitHamsu(s):
    S = s.split()
    for i in range(len(S)):
        for j in range(len(S[i])):
            print(S[i][len(S[i]) - j - 1] , end = '')
        if i != len(S) - 1:
            print(end = ' ')

for i in range(len(lst)):
    tmp = lst[i].split('<')
    if (len(tmp[0]) != 0):
        splitHamsu(tmp[0])
    if (len(tmp) == 2):
        print('<'+tmp[1]+'>', end = '')