S = input()
lst = []
for i in range(len(S)):
    lst.append(S[i:len(S)])
lst.sort()
for i in lst:
    print(i)