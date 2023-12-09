n = int(input())
check = False

setN, r = divmod(n,5)
if r == 0:
    check = True
    print(setN)
else:
    for i in range(setN,-1,-1):
        if (n - (i*5)) % 3 == 0:
            print(i + (n - (i*5)) // 3)
            check = True
            break

if not check:
    print(-1)