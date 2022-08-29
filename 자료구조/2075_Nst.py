import heapq
N = int(input())
heap = []
for i in range(N):
    a = list(map(int, input().split()))
    if not heap:
        for j in a:
            heapq.heappush(heap, j)
    else:
        for num in a:
            if heap[0] < num:
                heapq.heappush(heap, num)
                heapq.heappop(heap)
print(heap[0])