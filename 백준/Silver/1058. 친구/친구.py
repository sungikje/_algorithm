import sys
import heapq



n = int(sys.stdin.readline())
graph = []
result = []

for i in range(n):
    s = str(sys.stdin.readline().rstrip())
    s = s.replace('N','0')
    s = s.replace('Y','1')
    graph.append(list(map(int,s)))

for i in range(n):
    for j in range(n):
        if i == j:
            graph[i][j] = 0
        else:
            if graph[i][j] != 1:
                graph[i][j] = 999


for k in range(n):
    for a in range(n):
        for b in range(n):
            if a != b:
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])


max = 0
for i in range(n):
    cnt = 0
    for j in range(n):
        if graph[i][j] <= 2 and graph[i][j]!= 0:
            cnt += 1
    if cnt > max:
        max = cnt

print(max)