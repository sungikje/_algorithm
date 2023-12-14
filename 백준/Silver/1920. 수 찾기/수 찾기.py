n = int(input())
arrN = list(map(int,input().split(' ')))
m = int(input())
arrM = list(map(int,input().split(' ')))
arrN.sort()

def find_number(n, arr, start, end):

    if start > end:
        print(0)
        return False

    mid = (start+end)//2

    if arr[mid] > n:
        find_number(n, arr, start, mid-1)
    elif arr[mid] < n :
        find_number(n, arr, mid+1, end)
    else:
        print(1)
        return True

for i in arrM:
    find_number(i, arrN, 0, len(arrN)-1)