#include<stdio.h>
typedef struct Node
{
    char p[60];
    struct Node *rl,*ll;
}*node;

node create_node(FILE *fp)
{
node newnode;
newnode=(node)malloc(sizeof(struct Node));
if(newnode==NULL)
{
printf("Memory not allocated");
}
fgets(fp,50,newnode->p);
newnode->rl=NULL;
newnode->ll=NULL;
return newnode;
}

node insert_end(node head)
{
    node cur;
     FILE *fp=fopen("b.txt","r");
     for(int i=0;i<2;i++)
     {
node newnode=create_node(fp);
if(head==NULL)
{
head=newnode;}
else
{
cur=head;
while(cur->rl!=NULL)
{
cur=cur->rl;
}
cur->rl=newnode;
}
}
return head;
}

void display(node head)
{
node cur=head;
while(cur!=NULL)
{
cur=cur->rl;
}
}

void main()
{
    node head=NULL;
    int n,i;
    printf("Enter n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        head=insert_end(head);
    }
    display(head);
}
