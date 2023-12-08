def solution(id_list, report, k):
    answer = [0] * len(id_list)
    divReport = []
    checkReport = [0] * len(id_list)
    stopUser = []
    dic = {}
    count = 0
    
    emp = set(report)
    report = list(emp)
    
    for i in range(len(id_list)):
        dic[id_list[i]] = []
    
    for i in range(len(report)):
        divReport.append(report[i].split(' '))
    
    for i in range(len(divReport)):
        dic[divReport[i][1]].append(divReport[i][0])
    
    for i in dic:
        if len(dic[i]) >= k :
            stopUser.append(i)
    
    for i in stopUser:
        for j in dic[i]:
            answer[id_list.index(j)] += 1
    
    return answer