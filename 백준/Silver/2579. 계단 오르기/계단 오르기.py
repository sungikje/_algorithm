import sys

N = int(sys.stdin.readline())
ist = []
dp = []
for i in range(0,N):
    D = int(sys.stdin.readline())
    ist.append(D)

if N == 1:
    dp.append(ist[0])

elif N == 2:
    dp.append(ist[0])
    dp.append(max(ist[1], ist[0]+ist[1]))   
else:
    dp.append(ist[0])
    dp.append(max(ist[1], ist[0]+ist[1]))
    dp.append(max(ist[1]+ist[2], ist[0]+ist[2]))
    for i in range(3,len(ist)):
        dp.append(max(dp[i-3]+ist[i-1] + ist[i], dp[i-2]+ ist[i]))
print(dp.pop())