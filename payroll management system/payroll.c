#include <stdio.h>
#include <string.h>

// Structure to store employee details
struct Employee
{
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float pf;
    float netSalary;
};

// Function to calculate salary using pointers
void calculateSalary(struct Employee *e)
{
    e->hra = e->basicSalary * 0.20;
    e->da = e->basicSalary * 0.10;
    e->pf = e->basicSalary * 0.08;

    e->netSalary = e->basicSalary + e->hra
                   + e->da - e->pf;
}

// Function to add employee details
void addEmployee(struct Employee e[], int *n)
{
    printf("\nEnter Employee ID: ");
    scanf("%d", &e[*n].id);

    printf("Enter Employee Name: ");
    scanf(" %49[^\n]", e[*n].name);

    printf("Enter Basic Salary: ");
    scanf("%f", &e[*n].basicSalary);

    calculateSalary(&e[*n]);

    (*n)++;

    printf("\nEmployee added successfully!\n");
}

// Function to display all employees
void displayEmployees(struct Employee e[], int n)
{
    int i;

    if (n == 0)
    {
        printf("\nNo employee records found!\n");
        return;
    }

    printf("\n========== EMPLOYEE DETAILS ==========\n");

    for (i = 0; i < n; i++)
    {
        printf("\nEmployee ID   : %d", e[i].id);
        printf("\nEmployee Name : %s", e[i].name);
        printf("\nBasic Salary  : %.2f", e[i].basicSalary);
        printf("\nHRA           : %.2f", e[i].hra);
        printf("\nDA            : %.2f", e[i].da);
        printf("\nPF            : %.2f", e[i].pf);
        printf("\nNet Salary    : %.2f\n", e[i].netSalary);
    }
}

// Function to search employee
void searchEmployee(struct Employee e[], int n)
{
    int id, i, found = 0;

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (e[i].id == id)
        {
            printf("\nEmployee Found!\n");
            printf("ID         : %d\n", e[i].id);
            printf("Name       : %s\n", e[i].name);
            printf("Net Salary : %.2f\n", e[i].netSalary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee not found!\n");
    }
}

// Main function
int main()
{
    struct Employee e[100];

    int choice;
    int n = 0;

    do
    {
        printf("\n\n=================================");
        printf("\n       PAYROLL MANAGEMENT SYSTEM");
        printf("\n=================================");
        printf("\n1. Add Employee");
        printf("\n2. Display Employees");
        printf("\n3. Search Employee");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (n < 100)
                {
                    addEmployee(e, &n);
                }
                else
                {
                    printf("\nEmployee limit reached!");
                }
                break;

            case 2:
                displayEmployees(e, n);
                break;

            case 3:
                searchEmployee(e, n);
                break;

            case 4:
                printf("\nThank you for using Payroll System!");
                break;

            default:
                printf("\nInvalid choice! Please try again.");
        }

    } while (choice != 4);

    return 0;
}