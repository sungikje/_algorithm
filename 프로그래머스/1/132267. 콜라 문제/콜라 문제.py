def solution(a, b, n):
    answer = 0
    
    
    while True:
        if n <= a :
            if n == a:
                answer += b
            break
        share, rest = divmod(n,a)
        answer += (share*b)
        n = (share*b)+rest
    
    
    return answer