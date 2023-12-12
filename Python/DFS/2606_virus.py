N = int(input())
M = int(input())
graph = [[] * N for _ in range(N + 1)]
visited = [False] * (N + 1)
for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
result = 0
def dfs(start):
    visited[start] = True
    global result
    result += 1
    for i in graph[start]:
        if not visited[i]:
            dfs(i)
            visited[start] = True
dfs(1)
print(result - 1)