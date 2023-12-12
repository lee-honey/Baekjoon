N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
S = 0
A.sort()
B.sort(reverse = True)
for i in range(N):
    S += A[i] * B[i]
print(S)