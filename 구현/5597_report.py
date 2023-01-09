temp = [0 for _ in range(30)]
for _ in range(28):
    n = int(input())
    temp[n - 1] = 1
for i in range(30):
    if (temp[i] == 0):
        print(i + 1)

# l = [i for i in range (1, 31)]
# for _ in range(28):
#     n = int(input())
#     l.remove(n)

# l.sort()
# print(l[0])
# print(l[1])