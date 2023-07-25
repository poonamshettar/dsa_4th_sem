#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

struct Contact
{
    char name[50];
    char phone[15];
};

struct Contact h[size];

void insert()
{
    int hkey, i;
    printf("\nEnter the name: ");
    scanf("%s", h[size - 1].name);

    printf("Enter the phone number: ");
    scanf("%s", h[size - 1].phone);

    hkey = h[size - 1].name[0] % size; // first character as hash key

    for (i = 0; i < size; i++)
    {
        int index = (hkey + i) % size;
        if (h[index].name[0] == '\0')
        {
            h[index] = h[size - 1];
            break;
        }
    }

    if (i == size)
    {
        printf("\nElement cannot be inserted. Hash table is full.\n");
    }
}

void search()
{
    char key[50];
    printf("\nEnter the name to search: ");
    scanf("%s", key);

    int hkey = key[0] % size;

    for (int i = 0; i < size; i++)
    {
        int index = (hkey + i) % size;
        if (strcmp(h[index].name, key) == 0)
        {
            printf("Contact details found at index %d:\n", index);
            printf("Name: %s, Phone: %s\n", h[index].name, h[index].phone);
            return;
        }
    }

    printf("\nContact not found.\n");
}

void display()
{
    printf("\nContact details in the hash table are:\n");
    for (int i = 0; i < size; i++)
    {
        if (h[i].name[0] != '\0')
        {
            printf("At index %d:\n", i);
            printf("Name: %s, Phone: %s\n", h[i].name, h[i].phone);
        }
    }
}

int main()
{
    int opt;
    while (1)
    {
        printf("\nPress 1. Add contact\t2. Display  phonebook\t3. Search contact\t4. Exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid option. Try again.\n");
        }
    }
    return 0;
}
