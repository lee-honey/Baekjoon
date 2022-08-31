A, B = map(int,input().split())
C = int(input())

if B + C >= 60:
    A += int((B + C) / 60)
    B = (B + C) - 60 * int((B + C) / 60)
    if A >= 24:
        A -= 24
else:
    B = B + C
print(str(int(A)), str(int(B)))