import sys

N = int(input())
lst = []
for i in range(N):
    a, b = map(int, input().split())
    lst.append([a,b])
lst.sort(key = lambda x : (x[1], x[0])) #1 기준을 정렬 후 0 기준으로 정렬
for i in range(N):
    print(lst[i][0],lst[i][1])