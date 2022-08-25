import sys
N = int(sys.stdin.readline())
lst = []
for _ in range(N):
    a, b = input().split()
    lst.append([a, b])
lst.sort(key = lambda x : int(x[0]))
for i in lst:
    print(i[0], i[1])