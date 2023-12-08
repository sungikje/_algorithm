import heapq
def solution(scoville, K):
    answer = 0
    
    heap = []
    for i in scoville:
        heapq.heappush(heap,i)


    num = heapq.heappop(heap)
    while num < K:

        if len(heap) >= 2 :
            heapq.heappush(heap, num + heapq.heappop(heap)*2)
            answer += 1    
        else:
            if len(heap) == 1:
                if num + heapq.heappop(heap)*2 < K:
                    answer = -1
                else:
                    answer += 1
                break
            else:
                answer = -1
                break
        num = heapq.heappop(heap)
    
    return answer