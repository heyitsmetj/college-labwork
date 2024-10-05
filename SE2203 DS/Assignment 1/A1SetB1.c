#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct Employees
{
    int empno;
    char empname[50];
} emp[100];

void bubbleSort(struct Employees *emp, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j =  0; j < n - i - 1; j++)
        {
            if (strcmp(emp[j].empname, emp[j + 1].empname) > 0)
            {
                struct Employees temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }
}

int readfile(struct Employees *emp)
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
        fscanf(fp,"%d %s",&emp[i].empno,emp[i].empname);
        i++;
    }
    
    return i-1;
}

void display(struct Employees *emp,int n)
{
    int i;

    for ( i = 0; i < n; i++)
    {
        printf("\n %d %s",emp[i].empno,emp[i].empname);
    }
    
}
int main()
{
    int n;

    n = readfile(emp);

    printf("\n Structure after reading file: ");
    display(emp,n);

    bubbleSort(emp,n);

    printf("\n Structure after Sorting : ");
    display(emp,n);


   return 0;
}