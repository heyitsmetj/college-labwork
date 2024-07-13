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

int partition(int a[],int down , int up)
{
    int pivot = a[down];
    int i = down + 1;
    int j = up;
    int temp;
    
    do
    {
    
    while(a[i] < pivot)
    {
        i++;
    }
    
    while(a[j] > pivot)
    {
        j--;
    }
    
    if(i < j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
    }while(i<j);
    
    temp = a[down];
    a[down] = a[j];
    a[j] = temp;
    
    return j;
    
}

void quicksort (int a[], int down, int up)
{
    int pi;
    
  if (down < up)
	{
	  
	  pi = partition (a, down, up);	//pivot index after partition
	  quicksort (a, down, pi - 1);	//LHS
	  quicksort (a, pi + 1, up);	//RHS
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
  
  quicksort (a, 0, n - 1);

  printf ("\n Your Sorted Array: ");
  display (a, n);
  
  clock_t end_time = clock();
  
  double time_taken = ((double) end_time - start_time) / CLOCKS_PER_SEC;
  
  printf("\n Time take to execute program: %f seconds",time_taken);

  return 0;
  //end of code
}
