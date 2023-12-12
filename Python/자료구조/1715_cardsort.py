import sys
import heapq
N = int(input())
heap = []
result = 0
for i in range(N):
    heapq.heappush(heap,int(sys.stdin.readline()))
for i in range(N - 1):
    temp = heapq.heappop(heap) + heapq.heappop(heap)
    heapq.heappush(heap,temp)
    result += temp
print(result)