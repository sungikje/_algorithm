n = int(input())
answer = 0
sum = 0
for i in range(1, n+4):
    sum += i
    answer += 1
    if sum > n:
        print(answer-1)
        break