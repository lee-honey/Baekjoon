N, M = map(int, input().split())
lst = []
visited = [False] * N
def DFS(depth):
    if depth == M:
        print(' '.join(map(str, lst)))
        return
    for i in range(N):
        if not visited[i]:
            for j in range(i):
                visited[j] = True
            lst.append(i + 1)
            DFS(depth + 1)
            for j in range(i):
                visited[j] = False
            lst.pop()
DFS(0)