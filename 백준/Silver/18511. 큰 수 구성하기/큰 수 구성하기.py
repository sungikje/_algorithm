from itertools import product

n = list(map(int, input().split(' ')))
arr = list(map(int, input().split(' ')))
answer = 0

for j in range(1, len(str(n[0]))+1):
    for i in product(arr,repeat=j):
        if (int(''.join(str(_) for _ in i)) <= n[0]) and (answer <= int(''.join(str(_) for _ in i))):
            answer = int(''.join(str(_) for _ in i))
print(answer)
