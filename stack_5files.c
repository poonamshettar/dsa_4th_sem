#include <stdio.h>
#include <stdlib.h>
#define size 10
struct stack
{
    int data[size];
    int top;
};

void random(int n, FILE *fp1)
{
    int min, max, r;
    printf("Enter min and max");
    scanf("%d%d", &min, &max);
    for (int i = 0; i < n; i++)
    {
        fprintf(fp1, "%d ", (rand() % (max - min + 1)) + min);
    }
}
void stack_maintain(FILE *fp, struct stack *sptr)
{
    for (int i = sptr->top; i >= 0; i--)
    {
        fprintf(fp, "%d ", sptr->data[i]);
    }
}

void push(struct stack *sptr, FILE *fp1, FILE *fp2, FILE *fp3,FILE *fp5)
{
    sptr->top++;
    fscanf(fp1, "%d ", &sptr->data[sptr->top]);
    printf("pushed element is %d\n", sptr->data[sptr->top]);
    fprintf(fp2, "%d ", sptr->data[sptr->top]);
    fprintf(fp3, "%d ", sptr->data[sptr->top]);
    fprintf(fp5,"pushed element is %d\n", sptr->data[sptr->top]);
}

void pop(struct stack *sptr, FILE *fp4,FILE *fp5)
{
    if (sptr->top >= 0)
    {
        printf("popped element is %d\n", sptr->data[sptr->top]);
        fprintf(fp5,"popped element is %d\n", sptr->data[sptr->top]);
        fprintf(fp4, "%d ", sptr->data[sptr->top]);
        sptr->top--;
    }
}

void disp(struct stack *sptr, FILE *fp2)
{
    for (int i = sptr->top; i >= 0; i--)
    {
        printf("%d ", sptr->data[i]);
        fprintf(fp2, "%d ", sptr->data[i]);
    }
    printf("\n");
}

void main()
{
    FILE *fp1 = fopen("ip.txt", "w+");
    int n, ch;
    printf("Enter no of random nos to be generated: ");
    scanf("%d", &n);
    struct stack *sptr;
    struct stack s[10];
    sptr = s;
    sptr->top = -1;
    random(n, fp1);
    rewind(fp1);
    FILE *fp3 = fopen("push.txt", "w");
    FILE *fp4 = fopen("pop.txt", "w");
    FILE *fp5 = fopen("op.txt", "w");
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);

    while (1)
    {
        FILE *fp2 = fopen("stack.txt", "w");
        FILE *fp3 = fopen("push.txt", "a");
        FILE *fp4 = fopen("pop.txt", "a");
        FILE *fp5 = fopen("op.txt", "a");

        stack_maintain(fp2, sptr);
        fclose(fp2);
        printf("\nEnter choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push(sptr, fp1, fp2, fp3,fp5);
            break;
        case 2:
            pop(sptr, fp4,fp5);
            break;
        case 3:
            disp(sptr, fp2);
            break;
        default:printf("Invalid choice");
                exit(0);
        }
        fclose(fp3);
        fclose(fp4);
        fclose(fp5);
        fclose(fp2);

    }

}
