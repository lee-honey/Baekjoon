import sys
N, M = map(int, input().split())
lst = list(map(int, sys.stdin.readline().split()))
start, end = 1, max(lst)
while start <= end:
    mid = (start + end) // 2
    cnt = 0
    for i in lst:
        if i > mid:
            cnt += i - mid
    if cnt > M:
        start = mid + 1
    elif cnt == M:
        end = mid
        break
    else:
        end = mid - 1
print(end)