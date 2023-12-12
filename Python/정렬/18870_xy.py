N = int(input())
X = list(map(int, input().split()))
lst = list(set(X.copy()))
lst.sort()
x = []
dic = {lst[i]: i for i in range(len(lst))}
for i in range(len(X)):
    x.append(str(dic[X[i]]))
print(" ".join(x))
