N,M = map(int, input().split())
tmp = list(map(int, input().split()))
tmp.sort()
lst = []
prev = 0
visited = [False] * N
def dfs(depth):
    prev = 0
    if depth == M:
        print(' '.join(map(str, lst)))
        return
    for i in range(N):
        if tmp[i] != prev and visited[i] == False:
            lst.append(tmp[i])
            prev = tmp[i]
            for j in range(i + 1):
                visited[j] = True
            dfs(depth + 1)
            lst.pop()
            for j in range(i + 1):
                visited[j] = False
dfs(0)