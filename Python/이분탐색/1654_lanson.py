K, N = map(int, input().split())
ropes = []
for i in range(K):
    ropes.append(int(input()))
start, end = 1, max(ropes)
while start <= end:
    mid = (start + end) // 2
    cnt = 0
    for i in range(K):
        cnt += ropes[i] // mid
    if cnt >= N:
        start = mid + 1
    else:
        end = mid - 1
print(end)