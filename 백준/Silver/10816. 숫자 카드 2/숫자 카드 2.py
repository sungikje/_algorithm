import sys
from bisect import bisect_left, bisect_right

N = sys.stdin.readline()
array_n = list(map(int, sys.stdin.readline().split()))
M = sys.stdin.readline()
array_m = list(map(int, sys.stdin.readline().split()))
array_n.sort()


for i in range(0,len(array_m)):

    print(bisect_right(array_n, array_m[i])-bisect_left(array_n, array_m[i]),end=' ')