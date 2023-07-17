#include<stdio.h>
#define size 10
struct stack
{
    int data[size];
    int top;
};
void push(struct stack *sptr,int ch)
{
    sptr->top++;
    sptr->data[sptr->top]=ch;
}
int pop(struct stack *sptr)
{
    int num=sptr->data[sptr->top];
    sptr->top--;
    return num;
}

void main()
{
    struct stack *sptr;
    struct stack s[10];
    char p[20];
    int i=0,op1,op2;
    sptr=s;
    printf("Enter postfix numerical exp:");
    scanf("%s",p);
    sptr->top=-1;
    while(p[i]!='\0')
    {
      if(isdigit(p[i]))
      {
          push(sptr,p[i]-'0');
      }
      else
      {
         op2= pop(sptr);
         op1=pop(sptr);
      }
      switch(p[i])
      {
          case '+':push(sptr,op1+op2);
                    break;
          case '-':push(sptr,op1-op2);
                        break;
          case '*':push(sptr,op1*op2);
                    break;
          case '/':push(sptr,op1/op2);
                    break;
      }
      i++;
    }
    printf("%d ",pop(sptr));
}
