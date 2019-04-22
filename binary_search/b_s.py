import numpy as np

def binary_search(lists, value) : 
    low = 0
    high = len(lists)-1

    while low < high :
        mid = int((low + high) / 2)
        guess = lists[mid]
        print(guess)
        if guess == value :
            return mid
        if guess < value: 
            low = mid + 1
        else :
            high = mid - 1

    return 0;



#arr = (np.arange(100000))
arr = "123456789"
print(arr)
#arr = [0,1, 2, 3, 4, 5, 6, 7]

print(binary_search(arr, '6'))

