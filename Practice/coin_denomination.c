#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 100
struct stack
{
    char data[size];
    int top;
};

void push(struct stack *sptr,int num)
{
    if(sptr->top==size-1)
    {
    printf("stack overflow");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=num;

    }
}

void pop(struct stack *sptr,int n)
{
    int i,num,p=0,q=0,r=0,s=0,t=0;
    for(i=0;i<n;i++)
    {
    if(sptr->top==-1)
    {
        printf("Stack underflow");
        exit(0);
    }
    else
    {
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    if(num==1)
    {
        p++;
    }
    else if(num==2)
    {
        q++;
    }
    else if(num==5)
    {
        r++;
    }
    else if(num==10)

    {
        s++;
    }
    else
    {
        t++;
    }}
    printf("Coins of 1 re = %d\n",p);
     printf("Coins of 2 rs = %d\n",q);
     printf("Coins of 5 rs = %d\n",r);
     printf("Coins of 10 rs = %d\n",s);
    printf("Coins of invalid denominations = %d\n",t);
}


int main() {
int i,n,num;
    struct stack *sptr;
    struct stack s;
    sptr=&s;
    sptr->top=-1;
   scanf("%d",&n);
    if(n>0)
    {
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        push(sptr,num);

    }

    pop(sptr,n);
    }
    else
    {
        printf("Invalid number of coins");
        exit(0);
    }
    return 0;
}
