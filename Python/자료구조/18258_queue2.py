import sys
from collections import deque
queue = deque([])
N = int(sys.stdin.readline())
for i in range(N):
    str = sys.stdin.readline()
    if (str[:4] == 'push'):
        queue.append(int(str[5:]))
    elif (str[:3] == "pop"):
        if (len(queue) != 0):
            print(queue[0])
            queue.popleft()
        else:
            print(-1)
    elif (str[:5] == "front"):
        print(queue[0] if len(queue) != 0 else -1)
    elif (str[:4] == "back"):
        print(queue[len(queue) - 1] if len(queue) != 0 else -1)
    elif (str[:4] == "size"):
        print(len(queue))
    elif (str[:5] == "empty"):
        print(1 if len(queue) == 0 else 0)