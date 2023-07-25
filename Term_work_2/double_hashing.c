#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

struct book
{
    char name[10];
    int id;
} b[size];

// First hash function using modulo
int hash1(int key)
{
    return key % size;
}

// Second hash function using prime number
int hash2(int key)
{
    return 1 + (key % (size - 1));
}

void insert()
{
    printf("Enter book name: ");
    scanf("%s", b[size - 1].name);
    printf("Enter ID: ");
    scanf("%d", &b[size - 1].id);

    int h1 = hash1(b[size - 1].id);
    int h2 = hash2(b[size - 1].id);

    for (int i = 0; i < size; i++)
    {
        int index = (h1 + i * h2) % size;
        if (b[index].id == 0)
        {
            strcpy(b[index].name, b[size - 1].name);
            b[index].id = b[size - 1].id;
            printf("Book inserted at index %d\n", index);
            return;
        }
    }

    printf("Hash table is full. Cannot insert the book.\n");
}

void search()
{
    int search;
    printf("Enter the ID of the book to search: ");
    scanf("%d", &search);

    int h1 = hash1(search);
    int h2 = hash2(search);

    for (int i = 0; i < size; i++)
    {
        int index = (h1 + i * h2) % size;
        if (b[index].id == search)
        {
            printf("Book found at index %d:\n", index);
            printf("Name: %s, ID: %d\n", b[index].name, b[index].id);
            return;
        }
    }

    printf("Book not found.\n");
}

void display()
{
    printf("\nBooks in the hash table:\n");
    for (int i = 0; i < size; i++)
    {
        if (b[i].id != 0)
        {
            printf("At index %d:\n", i);
            printf("Name: %s, ID: %d\n", b[i].name, b[i].id);
        }
    }
}

int main()
{
    int opt;

    for (int i = 0; i < size; i++)
    {
        b[i].id = 0; // Initializing the hash table with 0 IDs
    }

    while (1)
    {
        printf("\nPress 1. Add book\t2. Search book\t3. Display list of books\t4. Exit\n");
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
            printf("\nInvalid\n");
        }
    }

    return 0;
}
