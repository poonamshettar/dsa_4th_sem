#include<stdio.h>
struct Node
{
char name[20],srn[20];
int dd,mm,yy;
struct Node * link;
};
typedef struct Node *node;


node create_node()
{
node newnode;
newnode=(node)malloc(sizeof(struct Node));
if(newnode==NULL)
{
printf("not all");
}
printf("Enter details: ");
scanf("%s%s%d%d%d",newnode->name,newnode->srn,&newnode->dd,&newnode->mm,&newnode->yy);
newnode->link=NULL;
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
        printf("%s %s %d %d %d\n",cur->name,cur->srn,cur->dd,cur->mm,cur->yy);
        cur=cur->link;
    }
    }
}

void display_registered(node head)
{
    node cur;
    if(head==NULL)
    {
        printf("Student list is empty");
    }
    else
    {
        printf("Students registered are:\n");
        cur=head;
        while(cur!=NULL)
        {
            if(cur->mm<=2&&cur->yy<=2022)
            {
                 printf("%s %s %d %d %d\n",cur->name,cur->srn,cur->dd,cur->mm,cur->yy);
            }
            cur=cur->link;
        }
    }
}

void display_not_registered(node head)
{
    node cur;
    if(head==NULL)
    {
        printf("Student list is empty");
    }
    else
    {
        printf("Students not registered are:\n");
        cur=head;
        while(cur!=NULL)
        {
            if(cur->yy>=2022)
            {
                 printf("%s %s %d %d %d\n",cur->name,cur->srn,cur->dd,cur->mm,cur->yy);
            }
            cur=cur->link;
        }
    }
}

void main()
{
    int ch,n,i;
    node head=NULL;
    printf("1.insert student\n2.display all\n3.display registered\n4.display not registered\n5.exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter no of students");
                scanf("%d",&n);

            for(i=0;i<n;i++)
            {
                head=insert_end(head);
            }
            break;
            case 2:display(head);
                    break;
            case 3:display_registered(head);
                    break;
            case 4:display_not_registered(head);
                        break;
            case 5:exit(0);
        }
    }
}
