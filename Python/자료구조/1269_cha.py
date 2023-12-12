a, b = map(int, input().split())
lst_a = set(list(map(int, input().split())))
lst_b = set(list(map(int, input().split())))
print(len(lst_b - lst_a) + len(lst_a - lst_b))