def solution(cacheSize, cities):
    answer = 0
    lruCache = []
    
    if cacheSize == 0:
        answer = 5 * len(cities)
    else:
        for i in cities:
            if i.upper() in lruCache:
                lruCache.remove(i.upper())
                lruCache.append(i.upper())
                answer += 1
            else:
                if len(lruCache) >= cacheSize:
                    del lruCache[0]
                    lruCache.append(i.upper())
                else:
                    lruCache.append(i.upper())
                answer += 5

    return answer