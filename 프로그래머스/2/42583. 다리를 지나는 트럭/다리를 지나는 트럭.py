def solution(bridge_length, weight, truck_weights):
    answer = 0
    ist = []
    time1 = []
    time2 = 1
    # 동시에 2대가 들어간다는 보장은 없이 진행
    while len(truck_weights) > 0:
        if sum(ist)+truck_weights[0] <= weight:
            ist.append(truck_weights[0])
            truck_weights.pop(0)
            time1.append(time2)
        time2+=1
        if (time1[0]+bridge_length <= time2):
            ist.pop(0)
            time1.pop(0)
    return time1[len(time1)-1]+bridge_length