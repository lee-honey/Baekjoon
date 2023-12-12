N, M = map(int, input().split())
lst = []
W, B = 0, 0
colors = ['W', 'B']
state = 0
state2 = 0
result = 0
real_res = 2500
for i in range(N):
    lst.append(list(input()))
for i in range(M - 8 + 1):
    state = 0
    if i % 2 == 1:
        colors = ['B', 'W']
    else:
        colors = ['W', 'B']
    for j in range(8):
        if lst[i][j] != colors[j % 2]:
            state += 1
    print(state)
for i in range(M - 8 + 1):
    state2 = 0
    if i % 2 == 1:
        colors = ['W', 'B']
    else:
        colors = ['B', 'W']
    for j in range(8):
        if lst[i][j] != colors[j % 2]:
            state2 += 1
    print(state2)
#     if state2 < state:
#         result = state2
#     else:
#         result = state
#     if real_res >= result:
#         real_res = result