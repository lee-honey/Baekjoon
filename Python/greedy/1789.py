N = int(input())
result = 1
for i in range(1, 100000):
    if i != 1:
        result += i
    if result <= N and N < result + i + 1:
        break
print(i)