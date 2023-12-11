word = input()
croa = ['c=','c-','dz=','d-','lj','nj','s=','z=']
arr = []
answer = 0

i = 0

while True:
    if i+1 >= len(word):
        break
    
    if word[i:i+2] in croa:
        word = word[i+2:len(word)]
    else:
        if word[i:i+3] in croa:
            word = word[i+3:len(word)]
        else:
            word = word[i+1:len(word)]
    answer += 1
if len(word) > 0 :
    print(answer + 1)
else:
    print(answer)