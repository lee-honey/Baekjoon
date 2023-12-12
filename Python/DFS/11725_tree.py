n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    for i in range(min(a, b),0,-1):
        if a % i == 0 and b % i == 0:
            tmp = i
            break
    print(tmp * (a // tmp) * (b // tmp))
    