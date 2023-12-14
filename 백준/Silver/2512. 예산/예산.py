n = int(input())
arr = list(map(int,input().split(' ')))
m = int(input())
arr2 = []
count = 0

if sum(arr) <= m:
    print(max(arr))
else:
    arr.sort()
    for i in arr:
        check = m//(n-count)
        if i <= check:
            m -= i
            count += 1
        else:
            print(check)
            break