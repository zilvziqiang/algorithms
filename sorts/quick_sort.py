
def quick_sort(arr) : 
    if len(arr) < 2 : 
        return arr

    base = arr[0]
    lessArr = [i for i in arr[1:] if i < base]
    bigArr = [i for i in arr[1:] if i > base]

    return quick_sort(lessArr) + [base] + quick_sort(bigArr)


arr = [1, 3, 4, 31,25 ,16,5559, 192923, 443,334 ,225,116]

print(quick_sort(arr))
