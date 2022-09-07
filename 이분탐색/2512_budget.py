N = int(input())
lst = list(map(int, input().split()))
M = int(input())
start, end = 1, max(lst)
while start <= end:
    mid = (start + end) // 2
    cnt = 0
    for i in range(N):
        if lst[i] >= mid:
            cnt += mid
        else:
            cnt += lst[i]
    if cnt <= M:
        start = mid + 1
    else:
        end = mid - 1
print(end)