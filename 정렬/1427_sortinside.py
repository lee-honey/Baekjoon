N = int(input())
array = []
while N >= 10:
    array.append(N % 10)
    N = N // 10
array.append(N)
array.sort()
i = 0
for _ in array:
    print(array[len(array) - i - 1], end='')
    i += 1