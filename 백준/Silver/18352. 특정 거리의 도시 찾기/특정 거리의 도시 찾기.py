import sys
import heapq





n, m, k, x = list(map(int,sys.stdin.readline().split()))
graph = [[] for _ in range(n+1)]
dist = [9999 for _ in range(n+1)]
q = []
count = 0

for i in range(m):
    a, b = list(map(int,sys.stdin.readline().split()))
    graph[a].append(b)

heapq.heappush(q,(0,x))
dist[x] = 0

while len(q) != 0:

    distC, dest = heapq.heappop(q)
    for i in graph[dest]:
        if dist[i] > distC + 1:
            dist[i] = distC + 1
            heapq.heappush(q,(dist[i],i))

for i in range(len(dist)):
    if dist[i] == k:
        count += 1
        print(i)
    
if count == 0:
    print(-1)