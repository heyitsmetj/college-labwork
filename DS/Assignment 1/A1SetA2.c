#include <stdio.h>
#include <string.h>

void bubbleSort(array[], int n) 
{
    for (int i = 1; i < n; i++)
	{
		int current = array[i];
		int j = i-1;
		while (array[j])
		{
			/* code */
		}
		
	}
}

int main() 
{

    int i,n;
	
	printf("Enter the no. of array elements:");
	scanf("%d",&n);
	
	int array[n];
	
	for(i=0;i<n;i++)
	{
		printf("Enter Element [%d]:",i+1);
		scanf("%d",&array[i]);
	}

	printf(" Your array: ");
	
	for(i=0;i<n;i++)
	{
		printf(" %d",array[i]);
	}

    bubbleSort(array, n);

printf(" Your sorted array: ");
	
	for(i=0;i<n;i++)
	{
		printf(" %d",array[i]);
	}

    return 0;
}