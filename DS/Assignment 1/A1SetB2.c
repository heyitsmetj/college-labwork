#include <stdio.h>
#include<stdlib.h>

struct Persons
{
    int personno;
    int personage;
}per[100];

void insertionSort(struct Persons *per, int n)
{
    for (int i = 1; i < n; i++)
    {
        struct Persons current = per[i];
        int j = i - 1;

        while (j >= 0 && per[j].personage > current.personage)
        {
            per[j + 1] = per[j];
            j = j - 1;
        }
        per[j + 1] = current;
    }
}

int readfile(struct Persons *per)
{
    char fname[20];
    int i=0;
    FILE *fp;

    printf("\n Enter filename to read: ");
    scanf("%s",fname);
    fp = fopen(fname,"r");

    if (fp == NULL)
    {
        printf("\n Error in opening file!");
    }

    while (!feof(fp))
    {
        fscanf(fp,"%d %d",&per[i].personno,&per[i].personage);
        i++;
    }
    
    return i-1;
}

void display(struct Persons *per,int n)
{
    int i;

    for ( i = 0; i < n; i++)
    {
        printf("\n %d %d",per[i].personno,per[i].personage);
    }
    
}
int main()
{
    int n;

    n = readfile(per);

    printf("\n Structure after reading file: ");
    display(per,n);

    insertionSort(per,n);

    printf("\n Structure after Sorting : ");
    display(per,n);


   return 0;
}