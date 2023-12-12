import sys

N = int(input())
lst = set(map(int, sys.stdin.readline().split()))
M = int(input())
lst2 = list(map(int, sys.stdin.readline().split()))
lst3 = [0 for _ in range(M)]
for i in range(M):
    if lst2[i] in lst:
        lst3[i] = 1
for i in lst3:
    print(i, end = ' ')