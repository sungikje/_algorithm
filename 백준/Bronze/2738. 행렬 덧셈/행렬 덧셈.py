n = list(map(int,input().split(' ')))
arr1 = []
arr2 = []
count = 0
result = [[] for _ in range(n[0])]

for i in range(n[0]):
    arr1.append(list(map(int,input().split(' '))))

for i in range(n[0]):
    arr2.append(list(map(int,input().split(' '))))

for i in range(n[0]):
    for j in range(n[1]):
        result[i].append(arr1[i][j] + arr2[i][j])
        if count <=1:
            print(arr1[i][j] + arr2[i][j], end=' ')
            count += 1
        else:
            print(arr1[i][j] + arr2[i][j], end='\n')
            count = 0