
import sys

n = int(input())
arr = []

for i in range(n):
    arr.append(sys.stdin.readline().rstrip())

arr = set(arr)
arr = list(arr)
arr.sort()
arr.sort(key=len)

for i in arr:
    print(i)