def solution(n):
    answer = 0
    
    fibo = [0,1]
    
    i = 0
    while len(fibo) <= n:
        fibo.append(fibo[i] + fibo[i+1])
        i += 1
    
    answer = (fibo[n-1] + fibo[n-2]) % 1234567
    
    return answer