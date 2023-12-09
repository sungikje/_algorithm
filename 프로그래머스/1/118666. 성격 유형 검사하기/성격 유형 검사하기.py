
def find_index(num,arr):
    
    for i in range(len(arr)):
        if num in arr[i]:
            return i
    
def solution(survey, choices):
    answer = ''
    returnIndex = [[],['R','T'],['C','F'],['J','M'],['A','N']]
    
    dic = {}

    dic[1] = {'R':0,'T':0}
    dic[2] = {'C':0,'F':0}
    dic[3] = {'J':0,'M':0}
    dic[4] = {'A':0,'N':0}
    
    for i in range(len(survey)):
        
        if choices[i] > 4:
            dic[find_index(survey[i][1], returnIndex)][survey[i][1]] += abs(choices[i]-4)
        elif choices[i] <4:
            dic[find_index(survey[i][0], returnIndex)][survey[i][0]] += abs(choices[i]-4)
    
    # print(dic)
    
    for i in range(1,5):
        answer += max(dic[i], key=dic[i].get)
        
    # print(answer)
    
    
    
    return answer