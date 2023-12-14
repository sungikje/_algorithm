n = int(input())
count = 0

while True:
    if n >=3:
        n -= 3
    else:
        if n >= 1:
            n -= 1
    count += 1
    if n == 0:
        break

if count % 2 != 0:
    print('SK')
else:
    print('CY')
