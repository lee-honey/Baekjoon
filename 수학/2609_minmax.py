a, b = map(int, input().split())

tmp = 0
for i in range(min(a,b), 0, -1):
    if a % i == 0 and b % i == 0:
        tmp = int(i)
        break
print(tmp)
print(tmp * (a // tmp) * (b // tmp))