import sys
from collections import deque

N = int(sys.stdin.readline())

visited = [False]*(N+1)
result = []
graph = []

for i in range(N+1):
    graph.append([])
    result.append([])


for i in range(N-1):
    a, b = list(map(int, sys.stdin.readline().split()))
    graph[a].append(b)
    graph[b].append(a)


def bfs(graph,start, visited, reuslt):
    queue = deque([start])
    visited[start] = True

    while queue:
        v = queue.popleft()
        # print(v,end='')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                # print('   자식 : ', i, '부모 : ',v)
                result[i].append(v)
                visited[i] = True
    
    return result

bfs(graph,1,visited,result)


for i in range(2,len(result)):
    print(result[i][0],end='\n')