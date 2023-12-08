def solution(people, limit):
    answer = 0
    
    
    boat = []
    people.sort(reverse=True)
    i = 0
    j = len(people)-1
    while i<=j:
        if people[i] + people[j] <= limit:
            i += 1
            j -= 1
        else:
            i+= 1
        answer += 1
    
    
    
    
    return answer