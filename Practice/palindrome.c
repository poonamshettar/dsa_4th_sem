#include<stdio.h>
#include<string.h>
#define size 10
struct stack
{
    char c[size];
    int top;
};

void push(struct stack *sptr,char p[20])
{
    if(sptr->top==size-1)
    {
        printf("stack overflow");
    }
    else
    { for(int i=0;i<strlen(p);i++)
    {

        sptr->top++;
        sptr->c[sptr->top]=p[i];
    }}
}

void disp(struct stack *sptr)
{
    for(int i=sptr->top;i>=0;i--)
 {
     printf("%s ",sptr->c[i]);
 }
}

void pop(struct stack *sptr,char p[20])
{
    char z[20];
    int i=0;
    while(sptr->top!=-1)
    {
        z[i]=sptr->c[sptr->top];
        i++;
        sptr->top--;
    }
    if(strcmp(z,p)==0)
    {
        printf("Its palindrome");
    }
    else printf("Not a palindrome");
}


void main()
{
    struct stack *sptr;
    struct stack s[10];
    sptr=s;
    sptr->top=-1;
    char p[20];
    printf("Enter string : ");
    scanf("%s",p);
    push(sptr,p);
    disp(sptr);
    pop(sptr,p);
}
