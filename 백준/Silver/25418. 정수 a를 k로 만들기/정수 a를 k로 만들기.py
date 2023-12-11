n = list(map(int,input().split(' ')))
count = 0

while True:
    if n[1] >= 2*n[0]:
        if n[1] % 2 == 0:
            n[1] /= 2
            count +=1
        else:
            n[1] -= 1
            n[1] /= 2
            count += 2
    else:
        count += n[1]-n[0]
        print(int(count))
        break

    if n[1] == n[0]:
        print(count)
        break