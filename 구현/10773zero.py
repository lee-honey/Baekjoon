K = int(input())
result = 0
temp = []

for _ in range (K):
    a = int(input())
    if a != 0 :
        temp.append(a)
    else:
        temp.pop(len(temp) - 1)
for i in temp:
    result += i
print(result)