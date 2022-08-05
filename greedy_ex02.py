n,m = map(int, input().split())
result = 0
for i in range(n):
    data = list(map(int, input().split()))
    min_value = min(data)
    result = max(result,min_value) #지금까지의 반복문중에 나왔던 값들과 비교(매 반복마)
print(result)
