import sys

N = int(sys.stdin.readline().strip())
arr = []

while N > 1:
    
    a, b = divmod(N,2)
    N = a
    arr.append(b)
arr.append(N)

for i in range(len(arr)-1,-1,-1):
    print(arr[i], end='')