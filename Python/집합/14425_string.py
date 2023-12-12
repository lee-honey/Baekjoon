N,M = map(int, input().split())
lst = set()
result = 0
for _ in range(N):
    lst.add(input())
for _ in range(M):
    str = input()
    if str in lst:
        result += 1
print(result)