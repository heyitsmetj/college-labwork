#include<stdio.h>

void main()
{
	int key=26,i,flag=0;
	
	int array[7]={11,5,45,26,12,34,19};

	printf(" Your array: ");
	
	for(i=0;i<7;i++)
	{
		printf(" %d",array[i]);
	}
	
	printf("\n Your key (x) = %d ",key);
	
	for(i=0; i<7;i++)
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











