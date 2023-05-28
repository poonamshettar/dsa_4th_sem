#include<stdio.h>
#include<time.h>
struct Node
{
int data;
struct Node * link;
};
typedef struct Node *node;

void random(int n,FILE *fp)
{
    srand(time(NULL));
    int i,z;
    for(i=0;i<n;i++)
    {
        z=rand()%100;
        fprintf(fp,"%d ",z);
    }
}

node create_node(int z)
{
node newnode;
newnode=(node)malloc(sizeof(struct Node));
if(newnode==NULL)
{
printf("not all");
}
newnode->data=z;
newnode->link=NULL;
return newnode;
}



node insert_end(node head,int z)
{
node cur;
node newnode=create_node(z);
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



node random1(node head,int n,FILE *fp)
{ int z;
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&z);
        head=insert_end(head,z);
    }
    return head;
}


node bubble_sort(node head,int n)
{node cur=head->link;
node prev=head;
int temp;
    for(int i=0;i<n;i++)
    {
        while(cur->link!=NULL)
        {  prev=cur;
         cur=cur->link;
            if(prev->data>cur->data)
           {
               temp=cur->data;
               cur->data=prev->data;
               prev->data=temp;
           }
        }
        prev=NULL;
        cur=head;
    }

    return head;
}

void disp(node head)
{
    node cur=head;
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->link;
    }
}
int main()
{
    int n,start,stop;
    float time_r;
    printf("Enter n:");
    scanf("%d",&n);
    FILE *fp=fopen("ev.txt","w+");
    random(n,fp);
    rewind(fp);
    node head=NULL;
    head=random1(head,n,fp);
    disp(head);
    start=clock();
    head=bubble_sort(head,n);
    stop=clock();
    time_r = (float)(stop - start) / CLOCKS_PER_SEC;
    printf("\n");
    disp(head);
    printf("\n%f",time_r);

}
