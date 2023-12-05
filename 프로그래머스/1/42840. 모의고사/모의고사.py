def solution(answers):
    answer = []
    num1 = [1,2,3,4,5]
    num2 = [2,1,2,3,2,4,2,5]
    num3 = [3,3,1,1,2,2,4,4,5,5]
    result = [0,0,0]

    check = 0
    check1 = 0
    check2 = 0
    check3 = 0

    while check < len(answers):
        if answers[check] == num1[check1]:
            result[0] += 1
        if answers[check] == num2[check2]:
            result[1] += 1
        if answers[check] == num3[check3]:
            result[2] += 1

        if check1+1 == len(num1):
            check1 = -1

        if check2+1 == len(num2):
            check2 = -1

        if check3+1 == len(num3):
            check3 = -1
        check += 1
        check1 += 1
        check2 += 1
        check3 += 1
    check = 0
    while check< len(result):
        if result[check] == max(result):
            answer.append(check+1)
        check += 1
    return answer