#include<stdio.h>
#define size 100
struct stack
{
char data[size];
int top;
};
void push(struct stack *sptr,char cha)
{
if(sptr->top!=size-1)
{
sptr->top++;
sptr->data[sptr->top]=cha;
}}
char pop(struct stack *sptr)
{
    char ch;
if(sptr->top!=-1)
{
ch=sptr->data[sptr->top];
sptr->top--;
}
return ch;
}

char peak(struct stack *sptr)
{
    char num;
    if(sptr->top!=-1)
    {
    num=sptr->data[sptr->top];
    }
    return num;
}
int precedence(char ch)
{
    switch(ch)
    {
        case '#':return 0;
                 break;
        case '(':return 1;
                 break;
        case '+':
        case '-':return 2;
                break;
        case '*':
        case '/':
        case '%':return 3;
                 break;
        case '^':return 4;
                 break;

    }
    return 0;

}
void postfix_conv(char infix[size])
{
struct stack s;
struct stack *sptr;
sptr=&s;
sptr->top=-1;
char postfix[size],ch,elem;
int i=0,k=0;
push(sptr,'#');
while(infix[i]!='\0')
{
ch=infix[i];
if(ch=='(')
{
push(sptr,ch);
}
else if(isalnum(ch))
{
postfix[k++]=ch;
}
else if(ch==')')
{
while(sptr->data[sptr->top]!='(')
{
postfix[k++]=pop(sptr);
}
elem=pop(sptr);
}
else
{
while(precedence(peak(sptr))>=precedence(ch))
{
postfix[k++]=pop(sptr);
}
push(sptr,ch);
}

i++;
}
while(sptr->data[sptr->top]!='#')
{
postfix[k++]=pop(sptr);
}
postfix[k]='\0';
printf("%s",postfix);
}

int main() {
char infix[size];
    printf("Enter infix expression: ");
    scanf("%s",infix);
    printf("Given Infix Expression: %s ",infix);
    printf("\nPostfix expression is: ");
    postfix_conv(infix);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
