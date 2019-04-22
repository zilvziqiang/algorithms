#include <stdio.h>


int bubble_sort(int *arr, int len)
{
	int *tarr = arr;
	int i=len-1, j=0;
	for(; i>=0; i--)
	{
		for(j=0; j<=i; j++)
		{
			if(j+1 <= i && tarr[j] > tarr[j+1])
			{
				int tmp = tarr[j];
				tarr[j] = tarr[j+1];
				tarr[j+1] = tmp;				
			}			
		}
		for(int i=0; i<len; i++)
			printf("%d ", tarr[i]);
		printf("\n");
	}

	return 0;
}


int main()
{
	int arr[] = {10, -4 ,4, 5, 6, 7, 1, 0 ,9, -3};
	
	int len = sizeof(arr)/sizeof(int);
	bubble_sort((int*)arr, len);

	for(int i=0; i<len; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
