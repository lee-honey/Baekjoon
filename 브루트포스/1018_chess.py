N, M = map(int, input().split())
lst = []
count = []
for i in range(N):
    lst.append(list(input()))
for a in range(N - 8 + 1):
    for b in range(M - 8 + 1):
        state = 0
        state2 = 0
        for i in range(a, a + 8):
            for j in range(b, b + 8): 
                if (i + j) % 2 == 0:
                    if lst[i][j] != 'W':
                        state +=1
                    if lst[i][j] != 'B':
                        state2 +=1
                else:
                    if lst[i][j] != 'B':
                        state +=1
                    if lst[i][j] != 'W':
                        state2 +=1
        count.append(min(state, state2))
print(min(count))