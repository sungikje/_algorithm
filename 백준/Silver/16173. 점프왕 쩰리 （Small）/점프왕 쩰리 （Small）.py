n = int(input())
point = []
answer = False

for i in range(n):
    arr = list(map(int,input().split(' ')))
    point.append(arr)

def find_load(x, y):
    global point
    global answer

    
    if x >= len(point) or y >= len(point):
        return
    

    if point[x][y] == -1:
        print('HaruHaru')
        exit()
    if point[x][y] == 0:
        return

    find_load(x+point[x][y],y)
    find_load(x,y+point[x][y])
    
find_load(0,0)
print('Hing')