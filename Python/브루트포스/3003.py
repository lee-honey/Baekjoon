chess = list(map(int,input().split()))
list = [1,1,2,2,2,8]
for i in range(len(list)):
    list[i] -= chess[i]
print(' '.join(map(str,list)))