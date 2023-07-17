#include<stdio.h>
typedef struct Node
{
    char name[10];
    long long int phone_no;
    struct Node *link;
}*node;

node create_node()
{
    node newnode=(node)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory not all");
    }
    printf("Enter name");
    scanf("%s",newnode->name);
    printf("Enter phone_no");
    scanf("%lld",&newnode->phone_no);
    newnode->link=NULL;
}

node delete_front(head)
{
  node cur=head;
  head=cur->link;
  free(cur);
  return head;
}

node insert_end(node head)
{
node cur;
node newnode=create_node();
if(head==NULL)
{
head=newnode;
}
else
{
cur=head;
while(cur->link!=NULL)
{
cur=cur->link;
}
cur->link=newnode;
}
return head;
}

void search_display(node head,char search[10])
{
    node cur=head;
    while(cur!=NULL)
    {
        if(strcmp(cur->name,search)==0)
           {
               printf("%lld",cur->phone_no);
               break;
           }
           cur=cur->link;
    }
}

node search_delete(node head)
{
    node cur,prev;
    int search,s=0;
    printf("Enter search");
    scanf("%d",&search);
    if(head==NULL)
    {
        printf("Empty");
    }
    else if(strcmp(head->name,search)==0)
    {
       head= delete_front(head);
    }
    else
    {   prev=NULL;
        cur=head;
        while(cur!=NULL)
        {
            if(strcmp(cur->name,search)==0)
            {

                s=1;
                break;
            }
             prev=cur;
            cur=cur->link;
        }
        if(s==1)
        {
            prev->link=cur->link;

                free(cur);
        }
    }
    return head;

}

void display(node head)
{
    node cur=head;
    if(head==NULL)
    {
        printf("Empty");
    }
    else
    {
    while(cur!=NULL)
    {
        printf("%s %lld",cur->name,cur->phone_no);
        cur=cur->link;
    }
    }
}

void main()
{
    node head=NULL;
    int ch;
    char search[10];
    printf("1.create new contact\n2.search contact\n3.delete contact\n4.display contact list\n");
    while(1)
    {
        printf("Enter choice");
        scanf("%d",&ch);
        switch(ch)
    {
        case 1:head=insert_end(head);
                break;
        case 2:printf("Enter contact to be searched");
                scanf("%s",search);
                search_display(head,search);
                break;
        case 3:printf("Enter name of the contact to be deleted");#include <stdio.h>
#include <string.h>
typedef struct Node
{
    char name[10];
    long long int phone_no;
    struct Node *link;
} *node;

node create_node()
{
    node newnode = (node)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory not all");
    }
    printf("Enter name");
    scanf("%s", newnode->name);
    printf("Enter phone_no");
    scanf("%lld", &newnode->phone_no);
    newnode->link = NULL;
}

node delete_front(head)
{
    node cur = head;
    head = cur->link;
    free(cur);
    return head;
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
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = newnode;
    }
    return head;
}

void search_display(node head, char search[10])
{
    node cur = head;
    while (cur != NULL)
    {
        if (strcmp(cur->name, search) == 0)
        {
            printf("%ld", cur->phone_no);
            break;
        }
        cur = cur->link;
    }
}

node search_delete(node head)
{
    node cur, prev;
    int search, s = 0;
    printf("Enter search");
    scanf("%d", &search);
    if (head == NULL)
    {
        printf("Empty");
    }
    else if (strcmp(head->name, search) == 0)
    {
        head = delete_front(head);
    }
    else
    {
        prev = NULL;
        cur = head;
        while (cur != NULL)
        {
            if (strcmp(cur->name, search) == 0)
            {

                s = 1;
                break;
            }
            prev = cur;
            cur = cur->link;
        }
        if (s == 1)
        {
            prev->link = cur->link;

            free(cur);
        }
    }
    return head;
}

void display(node head)
{
    node cur = head;
    if (head == NULL)
    {
        printf("Empty");
    }
    else
    {
        while (cur != NULL)
        {
            printf("%s %lld", cur->name, cur->phone_no);
            cur = cur->link;
        }
    }
}

void main()
{
    node head = NULL;
    int ch;
    char search[10];
    printf("1.create new contact\n2.search contact\n3.delete contact\n4.display contact list\n");
    while (1)
    {
        printf("Enter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insert_end(head);
            break;
        case 2:
            printf("Enter contact to be searched");
            scanf("%s", search);
            search_display(head, search);
            break;
        case 3:
            printf("Enter name of the contact to be deleted");
            search_delete(head);
            break;
        case 4:
            printf("The contact list:\n");
            display(head);
            break;
        }
    }
}
                search_delete(head);
                break;
        case 4:printf("The contact list:\n");
                display(head);
                break;
                }
    }
}
