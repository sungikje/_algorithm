def solution(N, number):
    answer = 0
    
    
    
    point = 0
    ist = []
    dp = []
    ist.append(N)
    dp.insert(0,ist)
    ist = []


    if N == number :
        answer = 1
    else:
        for i in range(1,8):  # 몇개로 이루어져있는지 개수 i
            for j in range(0,i):   # i개로 이루어져있는 경우 연산하는 경우의 수

                for k in dp[j]:

                    for z in dp[-j-1]:
                        ist.append(k + z)
                        ist.append(k - z)
                        ist.append(k * z)
                        if z != 0:
                            ist.append(k // z)
            ist.append(int(str(N)*(i+1)))
            s = set(ist)
            if number in s:
                point = i
                break
            else:
                dp.insert(i, s)
                ist = []
            # print("dp : ", dp)
        if point != 0:
            answer = point+1
        else:
            answer = -1
    
    
    
    return answer