def solution(X, Y):
    answer = []
    
    x = list(map(int,X))
    y = list(map(int,Y))
    
    # exchange = list(set(X)&set(Y))
    # exchange.sort(reverse=True)
    
    for i in (set(X)&set(Y)):
        for j in range(min(x.count(int(i)),y.count(int(i)))):
            answer.append(i)
    answer.sort(reverse=True)
    if len(answer) == 0:
        return '-1'
    else:
        if answer[0] == '0':
            return '0'
    return ''.join(answer)