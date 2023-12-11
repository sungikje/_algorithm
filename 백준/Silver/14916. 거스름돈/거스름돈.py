n = int(input())

num = n % 5

if n== 1 or n == 3:
    print(-1)
else:
    if num%2 == 0:
        print(n//5 + num//2)
    else:
        print((num+5)//2 + (n//5)-1)