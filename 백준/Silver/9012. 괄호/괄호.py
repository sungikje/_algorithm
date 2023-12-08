import sys

N = int(sys.stdin.readline())
# N = input()
arr = []
check = []

def findLeft(i):
    left = []
    right = []
    for j in range(0,len(i)//2):
        if i[j] == "(":
            left.append(i[j])
        else:
            right.append(i[j])
        if len(right) > len(left):
            return True

def findRight(i):
    left = []
    right = []
    for j in range(len(i)-1,len(i)//2-1,-1):
        if i[j] == "(":
            left.append(i[j])
        else:
            right.append(i[j])
        if len(right) < len(left):
            return True

for i in range(int(N)):
    n = sys.stdin.readline().strip()
    # n = input()
    arr.append(n)

for i in arr:
    if i[0] == ')' or i[len(i)-1] == '(' or len(i) % 2 != 0:
        check.append('NO')
    elif i.count('(') != i.count(')'):
        check.append('NO')
    else:
        if findLeft(i) or findRight(i):
            check.append('NO')
        else:
            check.append('YES')

for i in check:
    print(i)