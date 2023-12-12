import math

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

t = int(input())

for _ in range(t):
    n = int(input())
    for a in range(n//2, 0, -1):
        if isPrime(a) and isPrime(n - a):
            print(a, n - a)
            break

#규칙성 발견이 중요. *
#중점을 기준으로 -1, +1 해나갔을때의 결과가 정답