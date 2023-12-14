n = int(input())

def factorial(n):
    num = 1
    for i in range(1, n+1):
        num *= i
    return num
    

for i in range(n):
    ist = list(map(int,input().split(' ')))
    print(factorial(ist[1])//(factorial(ist[0])*factorial(ist[1]-ist[0])))