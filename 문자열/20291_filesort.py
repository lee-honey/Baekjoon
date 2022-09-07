import sys
input = sys.stdin.readline
N = int(input())
lst = {}
for i in range(N):
    file = input().strip()
    tmp = file[file.find('.') + 1:]
    if tmp in lst:
        lst[tmp] += 1
    else:
        lst.setdefault(tmp, 1)
lst2 = sorted(lst.items())
for i in lst2:
    print(i[0], i[1])