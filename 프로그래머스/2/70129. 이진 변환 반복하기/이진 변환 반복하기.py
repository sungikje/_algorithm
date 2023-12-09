def find_binary(n):
    
    result = []
    
    while n > 1 :
        n,y = divmod(n, 2)
        result.append(str(y))
    result.append(str(n))
    result.reverse()
    return ''.join(result)
    
def solution(s):
    answer = []
    deleteZero = 0
    count = 0
    
    while True:
        
        count += 1
        deleteZero += s.count('0')
        s = s.replace('0','')
        s = find_binary(len(s))
        if s == '1':
            break
    answer.append(count)
    answer.append(deleteZero)
    
    return answer