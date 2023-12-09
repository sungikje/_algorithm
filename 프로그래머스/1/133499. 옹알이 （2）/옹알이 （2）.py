def solution(babbling):
    answer = 0
    
    for i in babbling:
        prev = ''
        stack = ''
        for j in i:
            stack += j
            
            if prev != stack and (stack == 'aya' or stack == 'ye' or stack == 'woo' or stack == 'ma'):
                prev = stack
                stack = ''
        if len(stack) == 0:
            answer += 1
            
    
    return answer