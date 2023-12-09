def solution(citations):
    answer = 0
    citations.sort()
    
    for i,k in enumerate(citations):
        if k >= len(citations)-i :
            return len(citations)-i
    return answer