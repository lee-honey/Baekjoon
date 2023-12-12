import math
N = int(input())

def isPrime(num):
    if num == 0 or num == 1:
        return False 
    elif num == 2:
        return True
    else:
        for j in range(2, int(math.sqrt(num)) + 1):
            if num % j == 0:
                return False
        return True

for _ in range(N):
    num = int(input())
    while not isPrime(num):
        num += 1
    print(num)
