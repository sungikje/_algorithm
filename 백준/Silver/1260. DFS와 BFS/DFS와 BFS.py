import sys
from collections import deque

# graph 전처리
graph=[]
pgraph=[]
chc = list(map(int, sys.stdin.readline().split()))
check = [False]*(chc[0]+1)

for i in range(0,chc[0]+1):
    lst = []
    graph.append(lst)
    pgraph.append(lst)


for i in range(0,chc[1]):
    ist = list(map(int, sys.stdin.readline().split()))
    pgraph[ist[0]].append(ist[1])
    pgraph[ist[1]].append(ist[0])

for i in range(0,len(graph)):
    graph[i].sort()

# BFS, 넓이 우선
def findBfs(graph, start, check1):
    queue = deque([start])
    check1[start] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not check1[i]:
                queue.append(i)
                check1[i] = True
# DFS, 깊이 우선 탐색
def findDfs(graph, start, check2):
    check2[start] = True
    print(start, end=' ')
    for i in graph[start]:
        if not check2[i]:
            findDfs(graph, i, check2)

# print(graph)
findDfs(graph, chc[2],check)
check = [False]*(chc[0]+1)
print()
findBfs(graph, chc[2],check)