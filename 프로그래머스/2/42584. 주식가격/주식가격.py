from collections import deque
def solution(prices):
    
    arr = deque(prices)
    result = []
    while len(arr) > 0:
        n = arr.popleft()
        count = 0
        
        for i in arr:
            count += 1
            if n > i:
                break
                
        result.append(count)
        
    return result