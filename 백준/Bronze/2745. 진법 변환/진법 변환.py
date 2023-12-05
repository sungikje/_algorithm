import sys

chc = sys.stdin.readline().split()

sum = 0

ist = list(chc[0])
num = int(chc[1])

for i in range(0, len(ist)):
    if ord(ist[i]) >= 65:
        sum += (ord(ist[i])-55)*(num**(len(ist)-i-1))
    else:
        sum += int(ist[i])*(num**(len(ist)-i-1))

print(sum)