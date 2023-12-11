n = list(map(int,input().split(' ')))
floor = []
checkFloor = [[False] * n[1] for _ in range(n[0])] 
answer = 0

for i in range(n[0]):
    ist = list(input())
    floor.append(ist)

for i in floor:
    stack = []
    for j in range(len(i)):
        stack.append(i[j])
        if stack[len(stack)-1] == '-' and (j+1 >= len(i) or i[j+1] =='|'):
            answer += 1

for i in range(n[1]):
    stack = []
    for j in range(n[0]):
        stack.append(floor[j][i])
        if stack[len(stack)-1] == '|' and (j+1 >= n[0] or floor[j+1][i] =='-'):
            answer += 1

print(answer)