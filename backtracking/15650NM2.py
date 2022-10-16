N = 3
# M = 2
lst = []
visited = [False] * N
def dfs(depth, M):
    if depth == M:
        print(' '.join(map(str, lst)))
        return
    for i in range(N):
        if not visited[i]:
            for j in range(i+1):
                visited[j] = True
            lst.append(i + 1)
            dfs(depth + 1, M)
            for j in range(i+1):
                visited[j] = False
            lst.pop()
for i in range(N + 1):
    dfs(0, i)