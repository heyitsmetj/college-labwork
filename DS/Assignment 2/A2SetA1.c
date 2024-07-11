#include <stdio.h>
#include <string.h>

typedef struct {
    int empno;
    char empname[50];
} Employee;

void bubbleSort(Employee employees[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(employees[j].empname, employees[j + 1].empname) > 0) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *file = fopen("employee.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Employee employees[];
    int count = 0;

    while (fscanf(file, "%d %s", &employees[count].empno, employees[count].empname) != EOF) {
        count++;
    }

    fclose(file);

    bubbleSort(employees, count);

    printf("Sorted Employee Data:\n");
    for (int i = 0; i < count; i++) {
        printf("%d %s\n", employees[i].empno, employees[i].empname);
    }

    return 0;
}