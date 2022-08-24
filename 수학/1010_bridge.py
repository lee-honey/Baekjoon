T = int(input())
lst = []
num1, num2 = 1, 1
for _ in range(T):
    N, M = map(int, input().split())
    for i in range(N):
        num1 = num1 * (M - i)
        num2 = num2 * (N - i)
    lst.append(int(num1 / num2))
    num1, num2 = 1, 1
for i in lst:
    print(i)