#include<stdio.h>
#define size 100
struct stack
{
    int data[size];
    int top;
};
void push(struct stack *sptr,int n)
{
    if(sptr->top==size-1)
    {
        printf("Stack overflow");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=n;
    }

}

int pop(struct stack *sptr)
{int num;
    if(sptr->top!=-1)
    {
        num=sptr->data[sptr->top];
        sptr->top--;
    }
    return num;
}

int main()
{
    struct stack *sptr;
    struct stack s[10];
    sptr=s;
    sptr->top=-1;
    int n,rem;
    printf("Enter decimal number: ");
    scanf("%d",&n);
    while(n!=0)
    {
        rem=n%2;
        push(sptr,rem);
        n=n/2;
    }
    printf("\nIts binary equivalent is: ");
    while(sptr->top!=-1)
    {
        printf("%d",pop(sptr));

    }
}

