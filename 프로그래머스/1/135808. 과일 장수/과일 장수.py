def solution(k, m, score):
    answer = 0
    
    score.sort()
    eachBoxMin = []
    count = 0
    min = 9
    
    for i in range(len(score)-1,-1,-1):
        if score[i] <= min:
            min = score[i]
            count += 1
            if count == m:
                eachBoxMin.append(min)
                count = 0
    for i in eachBoxMin:
        answer += i*m
    
    return answer