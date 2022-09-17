import math
prime = [2]
def isPrime(num):
    if num == 1 or num == 0:
        return False
    elif num == 2:
        return True
    else:
        for j in range(2, int(math.sqrt(num)) + 1):
            if num % j == 0:
                return False
        return True
for i in range(3, 10001, 2):
    if isPrime(i):
        prime.append(i)
print(prime)
# lst = []
# min = 100000
# T = int(input())
# for _ in range(T):
#     N = int(input())
#     prime = []
#     min = 100000
#     for k in range(N):
#         if isPrime(k):
#             prime.append(k)
#     for i in prime:
#         for j in prime:
#             if i + j == N:
#                 if abs(i - j) <= min:
#                     min = abs(i - j)
#                     if i >= j:
#                         a = j
#                         b = i
#                     else:
#                         a = i
#                         b = j
#     lst.append((a, b))
# for i in range(len(lst)):
#     print(lst[i][0], lst[i][1])