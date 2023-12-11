import math


def find_prime(n):

    for i in range(2,int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True


n = list(map(int, input().split(' ')))


for i in range(n[0], n[1]+1):
    if i != 1 and find_prime(i):
        print(i)