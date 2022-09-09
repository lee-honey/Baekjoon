N, M = map(int, input().split())
lst = []
def dfs(depth):
    if depth == M:
        print(' '.join(map(str, lst)))
        return
    for i in range(N):
        lst.append(i + 1)
        dfs(depth + 1)
        lst.pop()
dfs(0)
