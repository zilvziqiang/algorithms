import numpy as np

def bubble_sort(arr) : 
	lens = len(arr)-1
	while(lens) :
		j = 0
		while(j<=lens):
			if(j+1<= lens and arr[j] > arr[j+1]) : 
				tmp = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = tmp	
			j = j+1	
		print(arr, lens)
		lens = lens-1  
	return arr;	 


arr = [11, 3, 0, 19, 40, 66, 100, 3234, 333, 444, 666, 124, 9, 8, 6, 4, 73]
bubble_sort(arr)
	
