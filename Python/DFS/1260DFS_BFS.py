import sys
from collections import deque
input=sys.stdin.readline

N,M,V = map(int, input().split())
graph = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a) #이렇게 해야 서로 연결이 됨

for i in range(len(graph)):
    graph[i].sort() #번호 작은 순서대로 방문해야 함

visited = [False] * (N + 1)

def dfs(start):
    print(start, end = ' ')  #일단 첫 발자국을 찍고
    visited[start] = True
    for i in graph[start]: #그래프 첫 연결된 길부터 쭉 훑으며
        if not visited[i]:
            dfs(i) #계속해서 재귀 - 깊이우선 탐색이므로
            visited[start] = True

def bfs(start):
    q = deque([start])
    visited[start] = True
    while q:
        v = q.popleft() #하나 꺼내고
        print(v, end= ' ')
        for i in graph[v]: #인접한것들 쫙 돌면서
            if not visited[i]:
                q.append(i) #큐에 추가함
                visited[i] = True
dfs(V)
visited = [False] * (N + 1)
print()
bfs(V)