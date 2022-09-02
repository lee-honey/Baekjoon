import sys

N = int(input())
lst = list(map(int, sys.stdin.readline().split()))
M = int(input())
lst2 = list(map(int, sys.stdin.readline().split()))
dic = {}
for j in range(N):
    if lst[j] not in dic :
        dic[lst[j]] = 1
    else:
        dic[lst[j]] += 1
print(' '.join(str(dic[i]) if i in dic else '0' for i in lst2))