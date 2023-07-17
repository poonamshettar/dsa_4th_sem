#include<stdio.h>
typedef struct Node
{
    int data;
    struct Node *link;
}*node;


node create_node(int x)
{
    node newnode=(node)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Not all");
    }
    newnode->data=x;
    newnode->link=NULL;
}

node insert1(node head,int y)
{
node cur;
node newnode=create_node(y);
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

node insert(node head)
{
    node cur=head;
    node head1=NULL;
    node head2=NULL;
    while(cur!=NULL)
    {
        if(cur->data<=0)
        {
        head1=insert1(head1,cur->data);
        }
        cur=cur->link;
    }
    printf("\n");
    cur=head;
    while(cur!=NULL)
    {
        if(cur->data>0)
        {
        head2=insert1(head2,cur->data);
        }
        cur=cur->link;
    }
    printf("Negative numbers in the list: ");
    display(head1);
    printf("\n");
    printf("Positive numbers in the list: ");
    display(head2);
    printf("\n");
}



node insert_end(node head,int n)
{
    int x,i;
    FILE *fp=fopen("nos.txt","r");
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d",&x);
        node newnode=create_node(x);
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            node cur=head;
            while(cur->link!=NULL)
            {
                cur=cur->link;
            }
            cur->link=newnode;
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
        printf("%d ",cur->data);
        cur=cur->link;
    }
    }
}



void main()
{
    int n;
    node head=NULL;
    printf("Enter n:");
    scanf("%d",&n);
    head=insert_end(head,n);
    display(head);
    printf("\n");
    insert(head);
}
