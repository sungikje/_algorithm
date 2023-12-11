def find_prime(n):

    for i in range(2,n):
        if n % i == 0:
            return False
    return True


a = int(input())
b = int(input())

answer = []

for i in range(a, b+1):
    if i != 1 and find_prime(i):
        answer.append(i)

if len(answer) == 0:
    print(-1)
else:
    print(sum(answer))
    print(answer[0])