#include <stdio.h>
#include <string.h>

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

    int i,n;
	
	printf("\n Enter the no. of array elements: ");
	scanf("%d",&n);
	
	int array[n];
	
	for(i=0;i<n;i++)
	{
		printf("\n Enter Element [%d]: ",i+1);
		scanf("%d",&array[i]);
	}

	printf("\n Your array: ");
	
	for(i=0;i<n;i++)
	{
		printf(" %d",array[i]);
	}

    bubbleSort(array, n);

printf("\n Your sorted array: ");
	
	for(i=0;i<n;i++)
	{
		printf(" %d",array[i]);
	}

    return 0;
}