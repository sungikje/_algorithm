import sys



arr = []

def find_s(n):
    arr = list(map(int,str(n)))
    sum = 0

    for i in range(len(arr)):
        sum += arr[i]*(factorial(len(arr)-i))

    return sum

def factorial(n):
    if n == 1 :
        return 1
    else:
        return n * factorial(n-1)

while True:
    n = int(sys.stdin.readline().strip())
    if n != 0:
        arr.append(n)
    else:
        break

for i in arr:
    print(find_s(i))