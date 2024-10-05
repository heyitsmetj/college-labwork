#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void display (int a[], int n)
{
  for (int i = 0; i < n; i++)
	{
	  printf (" %d", a[i]);
	}
}

void merge (int a[], int mid,int low, int high)
{
  int i, j, k, b[100];
  i = low;
  j = mid + 1;
  k = low;

  while (i <= mid && j <= high)
	{
	  if (a[i] < a[j])
		{
		  b[k] = a[i];
		  k++;
		  i++;
		}
	  else
		{
		  b[k] = a[j];
		  k++;
		  j++;
		}
	}

  while (i <= mid)
	{
	  b[k] = a[i];
	  k++;
	  i++;
	}

  while (j <= high)
	{
	  b[k] = a[j];
	  k++;
	  j++;
	}
	
	for(i=low;i<=high;i++)
	{
	    a[i] = b[i];
	}
}

void mergeSort (int a[], int low, int high)
{
  int mid;

  if (low < high)
	{
	  mid = (low + high) / 2;
	  mergeSort (a, low, mid);
	  mergeSort (a, mid + 1, high);
	  merge (a, mid, low, high);
	}
}

int main ()
{
    clock_t start_time = clock();
    
  int n=5, i;

  printf ("\n Enter the 5 elements: ");

  int a[n];
  
    for (i = 0; i < n; i++)
	{
	  printf ("\n Enter element[%d]: ", i + 1);
	  scanf ("%d", &a[i]);
	}
    
  printf ("\n Your Array: ");
  display (a, n);
  
  mergeSort (a, 0, n - 1);

  printf ("\n Your Sorted Array: ");
  display (a, n);
  
  clock_t end_time = clock();
  
  double time_taken = ((double) end_time - start_time) / CLOCKS_PER_SEC;
  
  printf("\n Time take to execute program: %f seconds",time_taken);

  return 0;
}
