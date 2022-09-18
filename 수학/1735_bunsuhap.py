import sys
input = sys.stdin.readline
def gcd(a, b):
    while a % b != 0:
        mod = a % b
        a = b
        b = mod
    return b
a, b = map(int, input().split())
c, d = map(int, input().split())
g = gcd(a * d + b * c, b * d)
print((a * d + b * c)//g, (b * d)//g)