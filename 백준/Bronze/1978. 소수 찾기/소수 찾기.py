def find_prime(n):

    for i in range(2,n):
        if n % i == 0:
            return False
    return True

n = int(input())
num = list(map(int,input().split(' ')))
answer = 0

for i in num:
    if i != 1 and find_prime(i):
        answer += 1
print(answer)