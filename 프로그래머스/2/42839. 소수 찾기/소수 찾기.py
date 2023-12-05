from itertools import permutations
def find_prime(n):
    
    if n == 1 or n == 0:
        return False
    else:
        for i in range(2,n):
            if n % i == 0:
                return False
    return True

def solution(numbers):
    answer = 0
    arr2 = []
    arr = list(map(int,numbers))
    
    for i in range(1,len(numbers)+1):
        for j in permutations(arr, i):
            arr2.append(int(''.join(map(str, j))))
    
    arr2 = set(arr2)
    
    for i in arr2:
        if find_prime(i):
            answer += 1
    
    return answer