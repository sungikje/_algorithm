import math
def solution(progresses, speeds):
    answer = []
    ist = []
    for i in range(0, len(progresses)):
        num = math.ceil((100-progresses[i])/speeds[i])

        if len(ist) == 0:
            ist.append(num)
        else :
            if ist[0]>= num:
                ist.append(num)
            else:
                answer.append(len(ist))
                ist = []
                ist.append(num)
    if len(ist) != 0:
        answer.append(len(ist))
    return answer