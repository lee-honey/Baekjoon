import sys
import heapq
N = int(input())
heap = []
for i in range(N):
    x = int(sys.stdin.readline())
    if x == 0:
        if not heap:
            print(0)
        else:
            print(heapq.heappop(heap))
    else:
        heapq.heappush(heap, x)