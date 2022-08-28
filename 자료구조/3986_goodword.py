import sys
result = 0
N = int(input())
for i in range(N):
    stack = list(sys.stdin.readline().strip())
    temp = []
    for j in range(len(stack)):
        if len(temp) == 0:
            temp.append(stack[j])
        else:
            if temp[len(temp) - 1] == stack[j]:
                temp.pop()
            else:
                temp.append(stack[j])
    if len(temp) == 0:
        result += 1
print(result)