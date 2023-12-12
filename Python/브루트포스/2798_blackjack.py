N, M = map(int,input().split())
lst = list(map(int, input().split()))
result = 0
for i in range(N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            if lst[i] + lst[j] + lst[k] <= M:
                if lst[i] + lst[j] + lst[k] > result:
                    result = lst[i] + lst[j] + lst[k]
print(result)