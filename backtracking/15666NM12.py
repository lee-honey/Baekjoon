N, M = map(int, input().split())
tmp = list(set(list(map(int, input().split()))))
tmp.sort()
lst = []
visited = [False] * len(tmp)
def dfs(depth):
    if depth == M:
        print(' '.join(map(str, lst)))
        return
    for i in range(len(tmp)):
        if not visited[i]:
            for j in range(i):
                visited[j] = True
            lst.append(tmp[i])
            dfs(depth + 1)
            for j in range(i):
                visited[j] = False
            lst.pop()
dfs(0)