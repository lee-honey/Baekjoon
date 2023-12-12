N,K = map(int, input().split())
temp = []
result = 0
for i in range(N):
    temp.append(int(input()))
for i in range(N - 1, -1, -1):
    if K // temp[i] >= 1:
        result += K // temp[i]
        K -= K // temp[i] * temp[i]
    elif K == 0:
        break
print(result)