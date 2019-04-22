#include <stdio.h>


int bs(int *p, int len, int value)
{
    int low = 0;
    int high = len-1;

    while( low < high )
    {
        int mid = (low + high)/2;
        int guess = p[mid];
        printf("guess=%d\n", guess);
        if(guess == value)
            return mid;
        if(guess < value)
            low = mid + 1;
        else 
            high = mid - 1;
    }

    return -1;
}


int main()
{
    int arr[] = {-4, -3, -1, 0, 1, 3 , 5 , 7, 8, 9};

    int i = bs(arr, sizeof(arr)/sizeof(int), 1);

    printf("index=%d\n", i);

}
