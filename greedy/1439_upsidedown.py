S = list(input())
result = 0
for i in range(1, len(S)):
    if S[i - 1] != S[i]:
        j = i - 1
        while i < len(S) and S[i] != S[j]:
            S[i] = S[j]
            i += 1
        result += 1
print(result)         