N = int(input())
i = 0
lst = []
result = 0
for i in range(1, N):
    lst = []
    result = i
    temp = i
    while i > 0:
        lst.append(int(i % 10))
        i = int(i / 10)
    for j in lst:
        result = result + j 
    if result == N:
        print(temp)
        break
else:
    print(0)