def find_divisior(num):
    divisorsList = []
    for i in range(1, int(num**(1/2)) + 1):
        if (num % i == 0):
            divisorsList.append(i) 
            if ( (i**2) != num) : 
                divisorsList.append(num // i)
    
    return len(divisorsList)
    

def solution(number, limit, power):
    answer = 0
    
    for i in range(1,number+1):
        if find_divisior(i) > limit:
            answer += power
        else:
            answer += find_divisior(i)
    
    return answer