
n = input()
_list = list(map(int, input().split()))
dp_p = [1] * len(_list)
dp_m = [1] * len(_list)

prev_p = _list[0]
prev_m = _list[0]
for i in range(0, len(dp_p)):
    if i == 0: continue

    if _list[i-1] < _list[i]:
        dp_p[i] = dp_p[i-1] + 1
    elif _list[i-1] > _list[i]:
        dp_m[i] = dp_m[i-1] + 1
    else:
        dp_p[i] = dp_p[i-1] + 1
        dp_m[i] = dp_m[i-1] + 1

max = 0
for i in range(0, len(dp_p)):
    high = dp_p[i] if dp_p[i] > dp_m[i] else dp_m[i]
    if max < high:
        max = high

# print(dp_p)
# print(dp_m)
print(max)