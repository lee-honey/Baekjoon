import math
W, H, X, Y, P = map(int, input().split())
result = 0
R = H / 2
for i in range(P):
    x, y = map(int, input().split())
    if (x < X):
        temp = math.pow((x - X) ,2) + math.pow((y - (Y + R)), 2)
        if (temp <= math.pow(R, 2)):
            result += 1
    elif(X <= x and x < X + W):
        if (Y <= y and y <= Y + H):
            result += 1
    else:
        temp = math.pow((x - (X + W)), 2) + math.pow((y - (Y + R)), 2)
        if (temp <= math.pow(R, 2)):
            result += 1
print(result)