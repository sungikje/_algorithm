def solution(food):
    answer = ''
    
    i = 1
    while True:
        if food[i] > 1:
            answer += str(i)
            food[i] -= 2
        else:
            if i+1<len(food):
                i += 1
            else:
                break
    answer += '0'
    for i in range(len(answer)-2,-1,-1):
        answer += answer[i]
    return answer