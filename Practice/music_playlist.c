#include <stdio.h>
#include <string.h>
struct Node
{
    char name[10];

    struct Node *rl;
    struct Node *ll;
};
typedef struct Node *node;

node create_node()
{
    node newnode;
    newnode = (node)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory not allocated");
    }
    printf("Enter Song name: ");
    scanf("%s", newnode->name);
    newnode->rl = NULL;
    newnode->ll = NULL;
    return newnode;
}

node insert_end(node head)
{
    node cur;
    node newnode = create_node();
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        cur = head;
        while (cur->rl != NULL)
        {
            cur = cur->rl;
        }
        newnode->ll = cur;
        cur->rl = newnode;
    }
    return head;
}

void search(node head)
{
    char search[20];
    printf("Enter search\n");
    scanf("%s", search);
    node cur = head;

    while (cur != NULL)
    {

        if (strcmp(cur->name, search) == 0)
        {
            printf("Found song\n");
            printf("%s\n", cur->name);
            if (cur->ll == NULL)
            {
                printf("NO previous song\n");
            }
            else
            {
                cur = cur->ll;
                printf("Previous song\n");
                printf("%s\n", cur->name);
            }
            cur = cur->rl;
            if (cur->rl == NULL)
            {
                printf("NO next song\n");
            }
            else
            {

                cur = cur->rl;
                printf("Next song\n");
                printf("%s\n", cur->name);
            }
        }
        cur = cur->rl;
    }
}

node delete_front(node head)
{
    node cur = head;
    head = head->rl;
    cur->rl = NULL;
    free(cur);
    return head;
}
node delete_end(node head)
{
    node cur, prev;
    if (head == NULL)
    {

        printf("Empty");
    }
    else if (head->rl == NULL)
    {
        free(head);
        head = NULL;
        printf("Deleted");
    }
    else
    {
        cur = head;
        while (cur->rl != NULL)
        {
            prev = cur;
            cur = cur->rl;
        }
        cur->ll = NULL;
        prev->rl = NULL;
    }
    return head;
}

node search_delete(node head)
{

    int s = 0;
    char search[10];
    node temp, cur, prev;
    printf("Enter search");
    scanf("%s", search);
    if (strcmp(head->name, search) == 0 && head->rl == NULL)
    {
        free(head);
        head = NULL;
        printf("Deleted");
    }
    else if (strcmp(head->name, search) == 0)
        head = delete_front(head);

    else
    {
        prev = NULL;
        cur = head;
        while (cur->rl != NULL)
        {

            if (strcmp(cur->name, search) == 0)
            {
                s = 1;
                break;
            }
            prev = cur;
            cur = cur->rl;
        }
        if (strcmp(cur->name, search) == 0)
        {
            head = delete_end(head);
        }
    }
    if (s == 1)
    {
        temp = cur->rl;
        prev->rl = cur->rl;
        temp->ll = cur->ll;
        cur->rl = cur->ll = NULL;
    }
    return head;
}

void display(node head)
{
    node cur = head;
    while (cur != NULL)
    {
        printf("%s\n", cur->name);
        cur = cur->rl;
    }
}

void main()
{
    node head = NULL;
    int n, i, ch;
    printf("1.Add song to playlist\n2.remove song from playlist\n3.search song n display next and previous song\n4.display playlist\n");
    while (1)
    {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insert_end(head);
            break;
        case 2:
            head = search_delete(head);
            break;
        case 3:
            search(head);
            break;
        case 4:
            display(head);
            break;
        }
    }
}
