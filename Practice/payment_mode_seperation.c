#include<stdio.h>
#include<string.h>
#define size 10
struct queue
{
    char name[10][size];
    int front,rear;
    char c[size];
};

void enqueue(struct queue*qptr)
{
    if(qptr->rear==size-1)
    {
        printf("Queue full");
    }
    else
    {
        qptr->rear++;
        scanf("%s ",qptr->name[qptr->rear]);
        scanf("%c",&qptr->c[qptr->rear]);
    }
}


void disp(struct queue *qptr)
{
      if((qptr->front==-1&&qptr->rear==-1)||(qptr->front==qptr->rear))
    {
        printf("Queue Empty\n");
    }
    for(int i=qptr->front+1;i<=qptr->rear;i++)
    {
        printf("%s %c \n",qptr->name[i],qptr->c[i]);
    }
}


void dequeue(struct queue *qptr)
{
    struct queue *pptr,*sptr;
    struct queue p[10],s[10];
    pptr=p;
    sptr=s;
    pptr->rear=sptr->rear=pptr->front=sptr->front=-1;
    while(qptr->front!=qptr->rear)
    {
    qptr->front++;
    if(qptr->c[qptr->front]=='O')
    {
       pptr->rear++;
       pptr->c[pptr->rear]=qptr->c[qptr->front];
       strcpy(pptr->name[pptr->rear],qptr->name[qptr->front]);
    }
    else
    {
       sptr->rear++;
       sptr->c[sptr->rear]=qptr->c[qptr->front];
       strcpy(sptr->name[sptr->rear],qptr->name[qptr->front]);
    }
    }
    printf("\nOnlineS:\n");
    disp(pptr);
    printf("\nCash:\n");
    disp(sptr);
}
void main()
{
    struct queue *qptr;
    struct queue q[10];
    int n;
    qptr=q;
    qptr->front=qptr->rear=-1;
    printf("Enter n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        enqueue(qptr);
    }
    disp(qptr);
    dequeue(qptr);
}


