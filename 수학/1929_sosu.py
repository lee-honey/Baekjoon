import math

M, N = map(int, input().split())
arr = []
def isPrime(num):
    if num == 1:
        return False
    elif num == 2:
        return True
    else:
        for j in range(2, int(math.sqrt(num)) + 1):
            if num % j == 0:
                return False
        return True
for i in range(M, N+1):
    if isPrime(i):
        print(i)