import sys
N = int(input())
lst = []
for i in range(N):
    lst.append(int(sys.stdin.readline()))
lst.sort()
max = lst[-1]
for i in range(0, N):
    if lst[N - i - 1] * (i + 1) > max:
        max = lst[N - i - 1] * (i + 1)
print(max)