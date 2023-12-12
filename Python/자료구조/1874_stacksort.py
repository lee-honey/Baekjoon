import sys
n = int(sys.stdin.readline())
stack = []
res = []
pp = 1
for i in range(n):
    num = int(sys.stdin.readline().strip())
    for i in range(pp, num + 1):
        stack.append(i)
        res.append("+")
        pp += 1
    if stack[-1] == num:
        stack.pop()
        res.append("-")
if len(stack) != 0:
    print("NO")
else:
    print('\n'.join(res))