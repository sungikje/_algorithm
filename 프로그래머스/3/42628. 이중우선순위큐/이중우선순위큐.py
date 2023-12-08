def solution(operations):
    answer = []
    heap = []

    for i in operations:
        if i == "D -1":
            if len(heap) != 0:
                heap.remove(min(heap))
        elif i == "D 1":                       
            if len(heap) != 0:
                heap.remove(max(heap))
        else:
            heap.append(int(i[2:len(i)]))

    if len(heap) > 0:
        answer.append(max(heap))
        answer.append(min(heap))
    else:
        answer.append(0)
        answer.append(0)
    return answer