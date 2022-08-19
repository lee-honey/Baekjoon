N = int(input())
lst=[]
x, y = 0, 0
for i in range(6):
    a, b = map(int, input().split())
    lst.append([a, b])
for i in range(6):
    if lst[i][0] == 4 or lst[i][0] == 3:
        if lst[i][1] > y:
            y = max(lst[i][1])
    elif lst[i][0] == 2 or lst[i][0] == 1:
        if lst[i][1] > x:
            x = lst[i][1]
for i in range(6):
    if lst[i][0] == lst[(i + 2) % 6][0]:
        if lst[(i + 1) % 6][0] == lst[(i + 3) % 6][0]:
            small = lst[(i + 1) % 6][1] * lst[(i + 2) % 6][1]
print(N * (x * y - small)) 