#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int array[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int current = array[i];
		int j = i - 1;
		while (array[j] > current && j >= 0)
		{
			array[j + 1] = array[j];
			j--;
		}

		array[j + 1] = current;
	}
}

int main()
{

	int i, n;

	printf("\n Enter the no. of array elements: ");
	scanf("%d", &n);

	int array[n];
	
	srand(time(0));

	for(i=0;i<n;i++)
	{
		array[i] = rand() % (10);
	}

	printf("\n Your random array: ");

	for (i = 0; i < n; i++)
	{
		printf(" %d", array[i]);
	}

	InsertionSort(array, n);

	printf("\n Your sorted array: ");

	for (i = 0; i < n; i++)
	{
		printf(" %d", array[i]);
	}

	return 0;
}