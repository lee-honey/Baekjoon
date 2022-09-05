N = int(input())
post = input()
nlst = []
dic = {}
stack = []
for i in range(N):
    nlst.append(int(input()))
for i in range(len(post)):
    if 'A' <= post[i] <= 'Z':
        dic[post[i]] = nlst[ord(post[i]) - ord('A')]
        stack.append(dic[post[i]])
    elif post[i] == '+':
        stack.append(stack.pop() + stack.pop())
    elif post[i] == '-':
        stack.append((-stack.pop() +stack.pop()))
    elif post[i] == '*':
        stack.append(stack.pop() * stack.pop())
    elif post[i] == '/':
        temp = stack.pop()
        stack.append(stack.pop() / temp)
print(format(stack[0], ".2f"))