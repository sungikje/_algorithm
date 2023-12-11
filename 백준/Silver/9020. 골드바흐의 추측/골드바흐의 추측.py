import math

def find_prime(n):
    for i in range(2,int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

n = int(input())

for i in range(n):
    newN = int(input())
    a = newN//2
    b = newN//2
    while a > 0:
        if find_prime(a) and find_prime(b):
            print(a,b)
            break
        else:
            a -= 1
            b += 1