#include <stdio.h>
#include<stdlib.h>

void bubbleSort(int array[], int n) 
{
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j+1]) 
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() 
{

    int i,n=5;
	int A[5] = {10,20,35,23,12};

	printf("\n A[5]: ");
	
	for(i=0;i<n;i++)
	{
		printf(" %d",A[i]);
	}

    bubbleSort(A, n);

printf("\n Your sorted array: ");
	
	for(i=0;i<n;i++)
	{
		printf(" %d",A[i]);
	}

    return 0;
}