#include<stdio.h>
#include<time.h>
#define size 10
struct stack
{
    int data[size];
    int top;
};

void random(FILE *fp,int n)
{

    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d ",rand()%10);
    }
}

void push(struct stack *sptr,FILE *fp)
{ while(!feof(fp))
{
    sptr->top++;
    fscanf(fp,"%d",&sptr->data[sptr->top]);
}
}

void pop(struct stack *sptr,FILE *fp)
{
    while(sptr->top!=0)
    {
    sptr->top--;
    fprintf(fp,"%d ",2*sptr->data[sptr->top]);
    }
}

void disp(struct stack *sptr)
{
    for(int i=sptr->top-1;i>=0;i--)
    {
        printf("%d ",sptr->data[i]);
    }
}
void main()
{
    struct stack *sptr;
    struct stack s;
    srand(time(NULL));
    sptr=&s;
    sptr->top=-1;
    FILE *fp1=fopen("in.txt","w+");
    FILE *fp2=fopen("out.txt","w+");
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    random(fp1,n);
    rewind(fp1);
    push(sptr,fp1);
    printf("Initial contents of stack:\n");
    disp(sptr);
    pop(sptr,fp2);
    rewind(fp2);
    sptr->top=-1;
    push(sptr,fp2);
    printf("\nContents of stack after doubling:\n");
    disp(sptr);

}
