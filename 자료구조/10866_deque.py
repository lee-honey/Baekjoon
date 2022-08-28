import sys
from collections import deque
deq = deque([])
N = int(sys.stdin.readline())
for i in range(N):
    str = sys.stdin.readline()
    if (str[:10] == 'push_front'):
        deq.appendleft(int(str[11:]))
    elif (str[:9] == 'push_back'):
        deq.append(int(str[10:]))
    elif (str[:9] == "pop_front"):
        if (len(deq) != 0):
            print(deq[0])
            deq.popleft()
        else:
            print(-1)
    elif (str[:8] == "pop_back"):
        if (len(deq) != 0):
            print(deq[len(deq) - 1])
            deq.pop()
        else:
            print(-1)
    elif (str[:5] == "front"):
        print(deq[0] if len(deq) != 0 else -1)
    elif (str[:4] == "back"):
        print(deq[len(deq) - 1] if len(deq) != 0 else -1)
    elif (str[:4] == "size"):
        print(len(deq))
    elif (str[:5] == "empty"):
        print(1 if len(deq) == 0 else 0)
