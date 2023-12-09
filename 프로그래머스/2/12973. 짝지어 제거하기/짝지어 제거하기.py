def solution(s):
    answer = -1

    arr = list(s)
    stack = []
    
    i = 0
    while True:
        stack.append(arr[i])
        i += 1
        
        if len(stack) > 1 :
            if stack[len(stack)-1] == stack[len(stack)-2]:
                stack.pop()
                stack.pop()
        if i >= len(arr):
            break
    
    if len(stack) != 0 :
        answer = 0
    else:
        answer = 1
        
    return answer