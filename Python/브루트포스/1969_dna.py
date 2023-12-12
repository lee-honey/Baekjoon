N, M = map(int, input().split())
lst = []
result = []
res = 0
acgt = [0 for i in range(26)] #A,C,G,T
for i in range(N):
    lst.append(input())
for i in range(M):
    for j in range(N):
        acgt[ord(lst[j][i]) - ord('A')] += 1
    result.append(chr(acgt.index(max(acgt)) + ord('A')))
    acgt = [0 for i in range(26)]
for i in range(N):
    for j in range(M):
        if (result[j] != lst[i][j]):
            res += 1
print(('').join(map(str, result)))
print(res)