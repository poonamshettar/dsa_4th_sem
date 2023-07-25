#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10

struct employee
{
    char name[10];
    int salary;
} e[size];

void insert()
{
    int k, i, index;
    printf("Enter employee name: ");
    scanf("%s", e[size - 1].name);
    printf("Enter salary: ");
    scanf("%d", &e[size - 1].salary);
    k = e[size - 1].name[0] % size;

    for (i = 0; i < size; i++)
    {
        index = (k + i * i) % size;
        if (e[index].name[0] == '\0')
        {
            e[index] = e[size - 1];
            printf("Employee inserted at index %d\n", index);
            return;
        }
    }
    printf("Employee cannot be inserted. Hash table is full.\n");
}

void search()
{
    char key[10];
    printf("Enter the name to search: ");
    scanf("%s", key);
    int k = key[0] % size;

    for (int i = 0; i < size; i++)
    {
        int index = (k + i * i) % size;
        if (strcmp(e[index].name, key) == 0)
        {
            printf("Employee details found at index %d:\n", index);
            printf("Name: %s, Salary: %d\n", e[index].name, e[index].salary);
            return;
        }
    }

    printf("Employee not found.\n");
}

void display()
{
    printf("\nEmployee details in the hash table are:\n");
    for (int i = 0; i < size; i++)
    {
        if (e[i].name[0] != '\0')
        {
            printf("At index %d:\n", i);
            printf("Name: %s, Salary: %d\n", e[i].name, e[i].salary);
        }
    }
}

int main()
{
    int opt;
    while (1)
    {
        printf("\n 1. add employee details \t2. Search employee \t3. Display employee list\t4. Exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid option. Try again.\n");
        }
    }
    return 0;
}
