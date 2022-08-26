import math
import sys
result = 0
lst = []
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
for i in range(2, 246913):
    if isPrime(i) == True:
        lst.append(i)
while (1):
    n = int(sys.stdin.readline())
    result = 0
    if n == 0:
        break
    for i in lst:
        if n < i and i <= 2 * n:
            result = result + 1
    print(result)