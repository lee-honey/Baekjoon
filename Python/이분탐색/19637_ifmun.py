import sys
N, M = map(int, sys.stdin.readline().split())
rank = [sys.stdin.readline().split() for _ in range(N)]
def bs(rank, cnt):
    start, end = 0, len(rank) - 1
    res = 0
    while start <= end:
        mid = (start + end) // 2
        if int(rank[mid][1]) >= cnt:
            end = mid - 1
            res = mid
        else:
            start = mid + 1 
    return res
for i in range(M):
    cnt = int(sys.stdin.readline())
    print(rank[bs(rank, cnt)][0])