def solution(triangle):
    answer = 0
    dp=[]
    for i in range(1,len(triangle)):
        for j in range(0,len(triangle[i])):
            if j == 0:
                triangle[i][j] = triangle[i-1][j] + triangle[i][j]
                # print(triangle)
            elif j == len(triangle[i])-1:
                triangle[i][j] = triangle[i-1][j-1] + triangle[i][j]
                # print(triangle)
            else:
                triangle[i][j] = max(triangle[i-1][j-1],triangle[i-1][j]) + triangle[i][j]
                # print(triangle)
    answer = max(triangle[len(triangle)-1])
    
    return answer