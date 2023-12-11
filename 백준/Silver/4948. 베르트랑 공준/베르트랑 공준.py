import math


def find_prime(n):

    for i in range(2,int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True


primeList = []

for i in range(2, 123457*2):
    if find_prime(i):
        primeList.append(i)

while True:
    answer = 0
    n = int(input())
    if n == 0:
        break
    for i in primeList:
        if n < i <= 2*n:
            answer += 1
    
    print(answer)