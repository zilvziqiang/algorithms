#include <stdio.h>


void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quick_sort(int *arr, int len)
{
	if(len < 2 || !arr)
	{
		return;
	}

	int start = 0;
	int base = arr[start++];
	int end = len-1;
	
	while(end > 0 && end > start)
	{
		int iSwap = 0;
		while(start < end)
		{
			if(arr[start] > base)
			{
				iSwap++;
				break;
			}
			start++;
		}

		while(end > 1 && start < end)
		{
			if(arr[end] < base)
			{
				iSwap++;
				break;
			}
			end--;
		}
	
		if(iSwap == 2)
		{
			swap(&arr[start], &arr[end]);
			if(++start != end)
			{
				end--;
			}
		}	
	}

	if(base > arr[start])
	{
		swap(&arr[0], &arr[start]);
	}

	quick_sort(arr, start);	
	quick_sort(arr+start, len - start);	
}


int arr[] = {110,9993, 123, 321, 3333, 44444, 55555, 100086, 1212, 22222,-1, 888222, 353, 999, 33, 6, 3, -100, -9,222, 33333, 666, 12,3334, 1223};
int main()
{
	quick_sort(arr, sizeof(arr)/sizeof(int));
	
	int i=0;
	for(;i<sizeof(arr)/sizeof(int);i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
