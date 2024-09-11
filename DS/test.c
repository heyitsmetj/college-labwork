//(Slip 17 10 marks) Bubble Sort using Normal Structure
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct Employees
{
    int empno;
    char empname[50];
    char addr[50];
} emp[100];

void bubbleSort(struct Employees *emp, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (emp[j].empno > emp[j + 1].empno)
            {
                struct Employees temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }
}


void display(struct Employees *emp,int n)
{
    int i;

    for ( i = 0; i < n; i++)
    {
        printf("\n %d %s %s",emp[i].empno,emp[i].empname,emp[i].addr);
    }
    
}
int main()
{
    int n;

    printf("\n Enter no. of records to be inserted: ");
    scanf("%d",&n);
    printf("\n Enter Records: \n");
    for (int i = 0; i < n; i++)
    {
        printf("\n [%d] Enter Employee No. : ",i+1);
        scanf("%d",&emp[i].empno);
        printf("\n [%d] Enter Employee Name : ",i+1);
        scanf("%s",emp[i].empname);
        printf("\n [%d] Enter Employee Address : ",i+1);
        scanf("%s",emp[i].addr);
    }
    

    printf("\n Structure after reading file: ");
    display(emp,n);

    bubbleSort(emp,n);

    printf("\n Structure after Sorting : ");
    display(emp,n);


   return 0;
}