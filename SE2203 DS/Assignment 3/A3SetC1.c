#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cities
{
	char city[20];
	int code;
};

typedef struct cities cit;

int readfile(cit *);
void display(cit *,int);
void linearsearch(cit *,int,char *);

int main()
{
	int n;
	char key[30];
	cit a[100];
		
	n=readfile(a);
	
	printf("\n Structure data after reading file: ");
	display(a,n);
	
	printf("\n Enter the city to be searched: ");
	scanf("%s",key);
	
	linearsearch(a,n,key);
	
	return 0;
}

int readfile( cit *a)
{
	char fname[20];
	int i=0;
	FILE *fp;
	
	printf("\n Enter filename to read: ");
	scanf("%s",fname);
	
	fp=fopen(fname,"r");
	
	if(fp == NULL)
	{
		printf("\n Error in opening file!");
		exit(0);
	}
	
	while(!feof(fp))
	{
		//printf("\naa");
		fscanf(fp,"%d %s",&a[i].code,a[i].city);
		i++;
	}
	
	return i-1;

}

void display(cit *a,int n)
{
	int i;
//	printf("\ndiaply");
	for(i=0;i<n;i++)
	{
		printf("\n %d %s",a[i].code,a[i].city);
	}
}

void linearsearch(cit *a, int n, char *key)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		if(strcmp(a[i].city,key)==0)
		{
			printf("\n %s city found. \n Code of %s city is %d.",key,key,a[i].code);
			break;
		}
	}
	
	if(i == n)
	{
		printf("\n City not found in the list \n");
	}
}









