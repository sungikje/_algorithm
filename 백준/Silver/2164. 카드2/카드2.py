import sys
from collections import deque

N = int(sys.stdin.readline())


arr = deque()

for i in range(1,N+1):
    arr.append(i)

while len(arr)  > 1:

    arr.popleft()
    arr.append(arr.popleft())

print(arr.pop())