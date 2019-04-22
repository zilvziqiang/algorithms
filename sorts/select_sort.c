#include <stdio.h>


int select_biggest(int *arr, int len)
{
	if(len < 0)
		return -1;
	int tmp = arr[0];
	int j;
	for(int i=1; i<len; i++)
	{
		if(arr[i] > tmp)
		{
			tmp = arr[i];
			j = i;
		}
	}

	arr[j] = arr[len-1];

	return tmp;
}


int arr[] = {0, 3331, 322, 313,334 ,999, 411, 31, 3 ,8, 33, 6, 44, 55, 77,123,99};
int main()
{
	int len = sizeof(arr)/sizeof(int);
	int i=0;
	for(i = len-1; i>0; i--)
	{
		arr[i] = select_biggest(arr, i+1);
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}
