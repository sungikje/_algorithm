import sys
from collections import Counter


n = int(input())
arr = []
arr2 = []
result = []

for i in range(n):
    arr.append(int(sys.stdin.readline().rstrip()))

result.append(round(sum(arr)/len(arr)))

arr.sort()
result.append(arr[(len(arr)-1)//2])

cnt = Counter(arr)

cnt1 = cnt.values()

for k, v in cnt.items():
    if v == max(cnt1):
        arr2.append(k)

arr2.sort()
if len(arr2)<=1:
    result.append(arr2[0])
else:
    result.append(arr2[1])

result.append(max(arr)-min(arr))

for i in result:
    print(i)