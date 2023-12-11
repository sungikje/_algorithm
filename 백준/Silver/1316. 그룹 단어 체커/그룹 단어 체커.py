n = int(input())
answer = 0

def find_group(word):
    arr = []

    for i in word:
        if len(arr) == 0:
            arr.append(i)
        else:
            if i in arr and i != arr[len(arr)-1]:
                return False
            else:
                arr.append(i)
    return True

for i in range(n):
    word = input()
    if find_group(word):
        answer += 1

print(answer)
