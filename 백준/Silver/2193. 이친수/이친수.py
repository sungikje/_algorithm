n = int(input())

_list = [0] * (n)

if n == 1 or n == 2:
    print(1)
else:
    _list[0] = 1
    _list[1] = 1
    for i in range(2, n):
        _list[i] = _list[i-1] + _list[i-2]
    print(_list[n-1])