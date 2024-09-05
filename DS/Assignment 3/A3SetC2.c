//Recursive Binary Search
#include <stdio.h>
int binsearch(int array[], int start, int end, int key);
void bubblesort(int array[], int n);
int main()
{
	int n;

	printf("\n Enter no. of elements: ");
	scanf("%d", &n);

	int array[n];

	for (int i = 0; i < n; i++)
	{
		printf("\n Enter element [%d] : ", i + 1);
		scanf("%d", &array[i]);
	}

	printf("Your Array: ");

	for (int i = 0; i < n; i++)
	{
		printf(" %d", array[i]);
	}

	bubblesort(array, n);

	printf("\n Your Sorted Array: ");

	for (int i = 0; i < n; i++)
	{
		printf(" %d", array[i]);
	}

	int key;
	printf("\n Enter element to be searched : ");
	scanf("%d", &key);

	int start = 0;
	int end = n - 1;

	int result = binsearch(array, start, end, key);

	if (result != -1)
	{
		printf("\n %d is present in the array.", key);
	}
	else
	{
		printf("\n %d is NOT present in the array.", key);
	}

	return 0;
}

void bubblesort(int array[], int n)
{
	int i, j, temp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int binsearch(int array[], int start, int end, int key)
{
	if (start <= end)
	{
		int mid = (start + end) / 2;

		if (array[mid] == key)
		{
			return mid;
		}
		if (array[mid] > key)
		{
			return binsearch(array, start, mid - 1, key);
		}

		if (array[mid] < key)
		{
			return binsearch(array, mid + 1, end, key);
		}
	}
	return -1;
}
