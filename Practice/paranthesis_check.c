#include<stdio.h>
#define size 10
struct stack
{
    int data[size];
    int top;
};

void push(struct stack *sptr,char ch)
{
    sptr->top++;
    sptr->data[sptr->top]=ch;
}

char pop(struct stack*sptr)
{
    char num=sptr->data[sptr->top];
    sptr->top--;
    return num;
}


int check()
{
    struct  stack *sptr;
    struct stack s[10];
    char p[20];
    sptr=s;
    sptr->top=-1;
    printf("Enter exp:");
    scanf("%s",p);
    int i=0;
    while(p[i]!='\0')
    {
        if(p[i]=='('||p[i]=='['||p[i]=='{')
            {
                push(sptr,p[i]);
            }
            else
                if(p[i]==')')
            {
                if(sptr->top==-1)
                {
                    return 0;
                }
                else if(pop(sptr)!='(')
                {
                    return 0;
                }
            }
            else if(p[i]==']')
            {

                if(sptr->top==-1)
                {
                    return 0;
                }
                else if(pop(sptr)!='[')
                {
                    return 0;
                }
            }
            else if(p[i]=='}')
            {

                if(sptr->top==-1)
                {
                    return 0;
                }
                else if(pop(sptr)!='{')
                {
                    return 0;
                }
            }
            i++;
    }
    if(sptr->top==-1)
    {
        return 1;
    }
    else
        return 0;
}
void main()
{
    int c=check();
    if(c==1)
    {
        printf("Valid");
    }
    else
        printf("Invalid");
}

