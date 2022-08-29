N,M = map(int, input().split())
lst = []
visited = [False] * N
def dfs(depth):
    if depth == M:
        print(' '.join(map(str, lst)))
        return
    for i in range(N):
        if not visited[i]:
            for j in range(i+1):
                visited[j] = True
            lst.append(i + 1)
            dfs(depth + 1)
            for j in range(i+1):
                visited[j] = False
            lst.pop()
dfs(0)