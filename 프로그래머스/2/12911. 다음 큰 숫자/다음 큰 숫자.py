def solution(n):
    answer = 0
    checkOne = 0
    
    
    def find_binary(n):
        arr = []
        
        while n >= 1:
            n, r = divmod(n,2)
            arr.append(r)
        return arr.count(1)
    
    def find_result(n, target):
        
        while True:
            if find_binary(n) == target:
                return n
            else:
                n += 1
        
    checkOne = find_binary(n)
    answer = find_result(n+1, checkOne)
    
    
    return answer