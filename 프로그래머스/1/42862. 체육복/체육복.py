def solution(n, lost, reserve):
    answer = 0
    check = []
    lost.sort()
    reserve.sort()
    
    for i in lost:
        if i in reserve:
            check.append(i)

    for i in check:
        if i in lost:
            lost.remove(i)
        if i in reserve:
            reserve.remove(i)

    for i in range(len(reserve)):
        if reserve[i]-1 in lost:
            lost.remove(reserve[i]-1)
        elif reserve[i]+1 in lost:
            lost.remove(reserve[i]+1)
    answer =  n - len(lost)   
    
    
    return answer