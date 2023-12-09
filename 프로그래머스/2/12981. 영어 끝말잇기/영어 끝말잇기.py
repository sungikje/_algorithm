def solution(n, words):
    answer = []
    checkTwice = []
    
    def return_answer(t,r, answer):
        
        
        if r != 0 :
            answer.append(r)
            answer.append(t+1)
        else:
            answer.append(n)
            answer.append(t)
        
        return answer
        
    
    
    
    for i in range(len(words)):
        if 2 <= len(words[i]) and len(words[i]) <= 50:
            if len(checkTwice) == 0:
                checkTwice.append(words[i])
            else:
                if checkTwice[len(checkTwice)-1][len(checkTwice[len(checkTwice)-1])-1] == words[i][0]:
                    if words[i] in checkTwice:
                        t, r = divmod(i+1,n)
                        answer = return_answer(t,r, answer)
                        if len(answer) != 0 :
                            break
                    else:
                        checkTwice.append(words[i])
                else:
                    t, r = divmod(i+1,n)
                    answer = return_answer(t,r, answer)
                    if len(answer) != 0 :
                        break
        else:
            t, r = divmod(i+1,n)
            answer = return_answer(t,r, answer)
            if len(answer) != 0 :
                break
    if len(answer) == 0:
        return [0,0]
    
    return answer