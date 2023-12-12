N,M = map(int, input().split())
visited = [False] * N
lst = []
def dfs(depth):
    if depth == M:
        print(' '.join(map(str, lst)))
        return
    for i in range(N):
        if not visited[i]:
            visited[i] = True
            lst.append(i + 1)
            dfs(depth + 1)
            visited[i] = False
            lst.pop()
dfs(0)
