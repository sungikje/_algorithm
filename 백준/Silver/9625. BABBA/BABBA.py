n = int(input())


_list = [[1, 0], [0, 1]]

if n == 1:
    print(0, 1)
elif n == 2:
    print(1, 1)
else:
    for i in range(0, n-1):
        tmp = list()
        tmp.append(_list[i][0] + _list[i+1][0])
        tmp.append(_list[i][1] + _list[i+1][1])
        _list.append(tmp)
    print(_list[-1][0], _list[-1][1])