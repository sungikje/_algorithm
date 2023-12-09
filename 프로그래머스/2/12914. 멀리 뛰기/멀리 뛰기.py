def solution(n):
    answer = 0
    arr = [1,2]
    
    if n == 1:
        return 1
    else:
        for i in range(2,n):
            arr.append(arr[i-1] + arr[i-2])
        answer = arr[n-1] % 1234567
    
    return answer