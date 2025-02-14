import math

n = int(input())
n_list = list(map(int, input().split()))

n_sum = 1
for i in n_list:
  n_sum *= i

m = int(input())
m_list = list(map(int, input().split()))
m_sum = 1
for i in m_list:
  m_sum *= i

res = math.gcd(n_sum, m_sum)
if res >= 10**9 :
  print(f"{res % 10**9:09d}")
else:
  print(res)