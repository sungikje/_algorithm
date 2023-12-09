def solution(s):
    answer = ''
    exS = list(map(int,s.split(' ')))
    answer += str(min(exS))
    answer += ' '
    answer += str(max(exS))
    return answer