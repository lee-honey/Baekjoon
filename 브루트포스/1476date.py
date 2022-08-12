E,S,M = map(int, input().split())
i = 0
while True:
  if (E % 15 == 0):
    E = 0
  if (S % 28 == 0):
    S = 0
  if (M % 19 == 0):
    M = 0
  if (i != 0 and i % 15 == E and i % 28 == S and i % 19 == M):
    break
  i += 1
print(i)