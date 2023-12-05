def solution(numbers, target):
    answer = 0
    
    def dfs(numbers, target, idx, ref):
        if idx == len(numbers):
            if ref == target:
                nonlocal answer
                answer += 1
        else:
            dfs(numbers, target, idx+1, ref + numbers[idx])
            dfs(numbers, target, idx+1, ref - numbers[idx])

    dfs(numbers, target, 0, 0)
    return answer