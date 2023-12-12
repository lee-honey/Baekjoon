N= int(input())
result = 0
nList = list(map(int, input().split()))
nList = sorted(nList)

i = N
while i > 0 :
    result += nList[N - i] * i
    i -= 1
print(result)