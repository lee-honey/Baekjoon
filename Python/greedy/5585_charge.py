N = int(input())
charge = 1000 - N
coin = [500, 100, 50, 10, 5, 1]
result = 0
for i in range(len(coin)):
    if (charge / coin[i]) >= 1:
        n = int(charge / coin[i])
        charge -= coin[i] * n
        result += n
print(result)