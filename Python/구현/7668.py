N = int(input())
list = []
result = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]

for _ in range(N):
    x,y = map(int, input().split())
    list.append([x, y])
for i in range(N):
    for j in range(i + 1,N):
        if list[i][0] > list[j][0] and list[i][1] > list[j][1]:
            result[j] += 1
        if list[i][0] < list[j][0] and list[i][1] < list[j][1]:
            result[i] += 1
for i in range(N):
    print(result[i])

