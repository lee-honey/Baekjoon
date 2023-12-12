T = int(input())
stack = []
answer = []
state = 1
lst = [[] for _ in range(T)]
for i in range(T):
    str = input()
    lst[i] = list(str)
for i in range(T):
    state = 1
    stack = []
    for j in range(len(lst[i])):
        if lst[i][j] == '(':
            stack.append(1)
        elif lst[i][j] == ')':
            if len(stack) == 0:
                state = 0
                break
            stack.pop()
    if len(stack) == 0 and state == 1:
        answer.insert(i,'YES')
    else:
        answer.insert(i,'NO')
for i in range(len(answer)):
    print(answer[i])