N = list(input())
result = 0
result = sum(int(i) for i in N)
if '0' not in N or result % 3 != 0:
    print(-1)
else:
    N.sort(reverse = True)
    print("".join(N))