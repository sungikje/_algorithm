def solution(brown, yellow):
    answer = []
    
    n = 1
    while True:
        if (n+2) * ((yellow/n)+2) == yellow + brown:
            answer.append(n+2)
            answer.append((yellow/n)+2)
            break
        else:
            n += 1
    answer.sort(reverse=True)
    
    return answer