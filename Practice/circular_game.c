#include<stdio.h>
struct Node
{
int data;
struct Node *link;
};
typedef struct Node * node;
node create_node()
{
node newnode;
newnode=(node)malloc(sizeof(struct Node));
if(newnode->link==NULL)
{
printf("Memory not allocated");
}
scanf("%d",&newnode->data);
newnode->link=newnode;
return newnode;
}

node insert_end(node tail)
{
node cur;
node newnode=create_node();
if(tail==NULL)
{
tail=newnode;
}
else
{
newnode->link=tail->link;
tail->link=newnode;
tail=newnode;
}
return tail;
}

void display(node tail)
{
node cur;
if(tail==NULL)
{
    printf("Empty");

}
else
{

cur=tail->link;
while(cur!=tail)
{
printf("%d ",cur->data);
cur=cur->link;
}

printf("%d ",cur->data);
}
}

int  count(node tail)
{
    int c=1;
    node cur;
    cur=tail->link;
    while(cur!=tail)
    {
        c++;
        cur=cur->link;
    }
    //printf("Count=%d",c);
    return c;

}


node delete_end(node tail)
{
   node cur,temp;
   if(tail==NULL)
   {
       printf("Empty");
   }
   else if(tail->link==tail)
   {
       tail=NULL;
       free(tail);
       printf("Empty");
   }
else{
        cur=tail->link;
   while(cur->link!=tail)
   {
       cur=cur->link;
   }
   cur->link=tail->link;
temp=tail;
   tail=cur;
   free(temp);
   }
return tail;
}

node delete_front(node tail)
{ node temp;
 if(tail==NULL)
 {
     printf("Empty");
 }
 else if(tail->link==tail)
 {
     free(tail);
     printf("Empty");
 }
  else{
    temp=tail->link;
    tail->link=temp->link;

    free(temp);
    return tail;
}
}

void delete(node tail,int x)
{
    node cur=tail->link,prev=NULL,temp=NULL;
    int z=count(tail);
    while (z!=1)
    {
        for(int i=0;i<x-1;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        temp=cur->link;
        if(cur->link==tail->link)
        {
            tail=delete_end(tail);
        }
        else if(prev->link==tail->link)
        {
            tail=delete_front(tail);
        }
        else
        {
        prev->link=cur->link;
        free(cur);
        }
        display(tail);
        printf("\n");
        z--;
        cur=temp;
        prev=NULL;
    }

}

void main()
{
    node tail=NULL;
    int n,x;
    printf("Enter n :");
    scanf("%d",&n);
    printf("Enter details: ");
    for(int i=0;i<n;i++)
    {
        tail=insert_end(tail);
    }
    display(tail);
    printf("\nEnter x: ");
    scanf("%d",&x);
    delete(tail,x);
}
