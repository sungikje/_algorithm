n = int(input())

def find_fibo(n):
    arrZero = [1, 0,1]
    arrOne = [0, 1,1]

    for i in range(1, n):
        arrZero.append(arrZero[i]+arrZero[i+1])
        arrOne.append(arrOne[i]+arrOne[i+1])

    print(arrZero[n], arrOne[n])

for i in range(n):
    find_fibo(int(input()))