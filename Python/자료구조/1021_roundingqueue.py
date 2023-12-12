from collections import deque
result = 0
N, M = map(int, input().split())
deq = deque(i for i in range(1, N + 1))
lst = list(map(int, input().split()))

for i in range(M):
    if deq.index(lst[i]) < len(deq) / 2:
        while (deq[0] != lst[i]):
            deq.append(deq.popleft())
            result += 1
    elif deq.index(lst[i]) >= len(deq) / 2:
        while (deq[0] != lst[i]):
            deq.appendleft(deq.pop())
            result += 1
    deq.popleft()
print(result)