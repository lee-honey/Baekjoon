S = input()
lst = []
for i in range(1, len(S) + 1):
    for j in range(len(S) + 1 - i):
        lst.append(S[j:j + i])
lst2 = list(set(lst))
print(len(lst2))