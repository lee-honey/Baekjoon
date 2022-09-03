from collections import deque
N = int(input())
lst = deque([i for i in range(N, 0, -1)])
while len(lst) > 1:
    lst.pop()
    lst.appendleft(lst.pop())
print(lst.pop())