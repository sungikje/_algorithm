def solution(ingredient):
    answer = 0
    
    burger = [1,2,3,1]
    
    i = 0
    while True:
        checkBurger = ingredient[i:i+4]
        if len(checkBurger) != 4:
            break
            
        else:
            if checkBurger == burger:
                answer += 1
                for _ in range(4):
                    del ingredient[i]
                if i - 4 >0:
                    i -= 4
                else:
                    i = -1
                
        i += 1
    
    return answer