from itertools import combinations

def solution(number):
    answer = 0
    
    threePop = list(combinations(number, 3))
    for i in threePop:
        if sum(i) == 0:
            answer += 1
    return answer