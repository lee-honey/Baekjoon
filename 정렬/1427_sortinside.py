N = int(input())
array = []
for i in str(N):
    array.append(int(i))
array.sort(reverse = True)
for _ in array:
    print(_, end="")