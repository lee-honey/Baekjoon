from collections import deque

N, K = map(int, input().split())
lst = [i for i in range(N, 0, -1)]
deq = deque(lst)
lst2 = []
while len(deq) > 0:
    for i in range(K - 1):
        deq.appendleft(deq.pop())
    lst2.append(str(deq.pop()))
print('<'+', '.join(lst2)+'>')
