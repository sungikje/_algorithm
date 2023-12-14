def solution(n):
    answer = 0
    
    check = [True] * (n+1)
    check[0] = False
    check[1] = False
    
    for i in range(2, int(n ** 0.5)+1):
        if check[i] == True:
            for j in range(2*i, n+1, i):
                check[j] = False
    
    answer = check.count(True)
    
    
    return answer