import heapq
import sys

def dijkstra(start, distance, graph):
    q = []
    heapq.heappush(q,(0,start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        # print("node : ",now)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q,(cost,i[0]))

                
def solution(n, vertex):
    answer = 0
    vertex.sort()
    INF = int(1e9)
    graph = [[] for i in range(n+1)]
    distance = [INF]*(n+1)
    answer = 0
    
    
    for i in range(len(vertex)):
        graph[vertex[i][0]].append((vertex[i][1],1))
        graph[vertex[i][1]].append((vertex[i][0],1))
    
    dijkstra(1, distance, graph)
    max = distance[1]
    for i in range(len(distance)):
        if distance[i] != INF and max <= distance[i]:
            max = distance[i]
    for i in range(len(distance)):
        if distance[i] == max:
            answer += 1
    
    return answer