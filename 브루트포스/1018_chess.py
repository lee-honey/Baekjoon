N, M = map(int, input().split())
lst = []
W, B = 0, 0
colors = ['W', 'B']
state = 0
state2 = 0
for i in range(N):
    lst.append(list(input()))
for i in range(N):
    if i % 2 == 1:
        colors = ['B', 'W']
    else:
        colors = ['W', 'B']
    for j in range(M):
        if lst[i][j] != colors[j % 2]:
            state += 1
for i in range(N):
    if i % 2 == 1:
        colors = ['W', 'B']
    else:
        colors = ['B', 'W']
    for j in range(M):
        if lst[i][j] != colors[j % 2]:
            state2 += 1
print(state2)

# 8*8 체스판으로 자를것