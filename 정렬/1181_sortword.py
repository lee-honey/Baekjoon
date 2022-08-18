N = int(input())
lst = set()
lst2 = []
lst3 = []
max = 0
for i in range(N):
    lst.add(input())
for i in lst:
    lst2.append(i)
lst2.sort()
lst2.sort(key = len)
print(*lst2, sep='\n')