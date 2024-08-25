//Linear Search
#include<stdio.h>

void main()
{
	int key,i,n,flag=0;
	
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
	
	printf("\n Enter the element to search: ");
	scanf("%d",&key);
	
	printf("\n Your key = %d ",key);
	
	for(i=0; i<n;i++)
	{
		if(key == array[i])
		{
			flag = 1;
			break;
		}
	}
	
	if(flag != 0)
	{
		printf("\n %d is at %d position\n",key,i+1);
	}
	else
	{
		printf("\n %d not found in Array\n",key);
	}
}