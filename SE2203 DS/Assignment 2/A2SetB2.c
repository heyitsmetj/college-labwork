#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void rarray (int a[], int n)
{
  srand(time(0));

  for (int i = 0; i < n; i++)
	{
	  a[i] = rand () % (10);
	}
}



int main ()
{
  int n, i;

  printf ("\n Enter the size of array: ");
  scanf ("%d", &n);

  int a[n];

  rarray (a, n);

  printf ("\n Your Random Array: ");

  display (a, n);

  mergeSort (a, 0, n - 1);

  printf ("\n Your Sorted Array: ");
  display (a, n);

  return 0;
}
