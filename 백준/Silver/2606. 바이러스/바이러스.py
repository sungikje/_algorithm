n = int(input())
r = int(input())

check = [False for i in range(n+1)]
check[1] = True
arr = [[] for i in range(n+1)]

for i in range(r):
    empty = list(map(int,input().split(' ')))
    arr[empty[0]].append(empty[1])
    arr[empty[1]].append(empty[0])

def find_virus(check,arr,n):

    if len(arr[n]) != 0 :

        for i in range(len(arr[n])):

            if not check[arr[n][i]]:
                check[arr[n][i]] = True
                find_virus(check,arr, arr[n][i])

find_virus(check,arr,1)
print(check.count(True)-1)