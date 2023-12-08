from collections import deque


num = int(input())
loc = []
INF = 1e9

for i in range(num):
    ist = list(map(int, input().split()))
    loc.append(ist)

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

currX = 0
currY = 0
currS = 2

for i in range(num):
    for j in range(num):
        if loc[i][j] == 9:
            currX = i
            currY = j

def findDistance():

    dist = [[-1] * num for _ in range(num)]
    dist[currX][currY] = 0
    loc[currX][currY] = 0

    while q:
        x,y = q.popleft()
        
        for i in range(4):
            newX = x + dx[i]
            newY = y + dy[i]
            if 0 <= newX and newX < num and 0 <= newY and newY < num:
                if dist[newX][newY] == -1 and loc[newX][newY] <= currS:
                    dist[newX][newY] = dist[x][y] + 1
                    q.append([newX, newY])
        
    return dist

def eatF(dist):

    min_dist = INF

    for i in range(num-1,-1,-1):
        for j in range(num-1,-1,-1):
            if dist[i][j] != 0 and dist[i][j] != -1 and 1 <= loc[i][j] and loc[i][j] <currS:
                if dist[i][j] <= min_dist:
                    min_dist = dist[i][j]
                    currX = i
                    currY = j
    
    if min_dist != INF:
        return currX, currY, min_dist
    else:
        return None

result = 0
ate = 0

while True:
    q = deque()
    q.append([currX, currY])

    value = eatF(findDistance())
    # print(value)

    if value == None:
        break
    else:
        currX = value[0]
        currY = value[1]
        loc[currX][currY] = 0
        # for i in loc:
        #     print(i)
        # print('')
        # print('')
        result += value[2]
        ate += 1
        if ate>= currS:
            currS += 1
            ate = 0

print(result)
