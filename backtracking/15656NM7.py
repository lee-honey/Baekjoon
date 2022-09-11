N, M = map(int, input().split())
tmp = list(map(int, input().split()))
tmp.sort()
lst = []
def dfs(depth):
    if depth == M:
        print(' '.join(map(str, lst)))
        return
    for i in range(N):
        lst.append(tmp[i])
        dfs(depth + 1)
        lst.pop()
dfs(0)