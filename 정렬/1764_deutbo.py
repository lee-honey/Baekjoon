N, M = map(int, input().split())
a = set()
b = set()
for i in range(N):
    a.add(input())
for i in range(M):
    b.add(input())
c = sorted(list(a.intersection(b)))
print(len(c))
print('\n'.join(c))