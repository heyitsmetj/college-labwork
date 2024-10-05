//Insertion Sort
#include <stdio.h>

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

	for (i = 0; i < n; i++)
	{
		printf("\n Enter Element [%d]: ", i + 1);
		scanf("%d", &array[i]);
	}

	printf("\n Your array: ");

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