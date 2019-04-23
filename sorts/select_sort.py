

def select_biggest(lists, lens) : 
    if len(lists) < 2 :
        return

    tmp = lists[0]
    index = 0
    for i in range(lens) : 
        if tmp < lists[i] :
            tmp = lists[i]
            index = i

    lists[index] = lists[lens-1]   
    print(tmp, index, lens-1)
    return tmp;



arr = [999, 1, 3, 4, 5 , 44, 33, 22 ,555, 6, 42, 7, -1, 99, 10002, 34242, -10]


lens = len(arr)
while (lens > 1) :
    arr[lens-1] = select_biggest(arr, lens)
    lens -= 1

print(arr)

