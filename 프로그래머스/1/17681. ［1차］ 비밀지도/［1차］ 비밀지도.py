def solution(n, arr1, arr2):
    answer = []
    
    def todo(x,n):
        ist = []
        while x > 1:
            a, b = divmod(x,2)
            ist.append(b)
            x = a
        ist.append(x)
        for i in range(len(ist),n):
            ist.append(0)
        ist.reverse()
        return ist

    for i in range(0, n):
        st = ''
        arr1result = todo(arr1[i],n)
        arr2result = todo(arr2[i],n)

        for i in range(0, n):
            if arr1result[i] == 1 or arr2result[i] == 1:
                st += '#'
            else:
                st += ' '
        answer.append(st)


    return answer