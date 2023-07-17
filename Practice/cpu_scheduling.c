#include <stdio.h>
#include <stdlib.h>
#define SI 100
struct queue
{
    int process[SI];
    int time[SI];
    int front, rear;
};
void enqueue(struct queue *qptr, int num1, int num2)
{
    if (qptr->rear == -1 && qptr->front == -1)
    {
        qptr->front = qptr->rear = 0;
        qptr->process[qptr->rear] = num1;
        qptr->time[qptr->rear] = num2;
    }
    else if ((qptr->rear + 1) % SI == qptr->front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        qptr->rear = (qptr->rear + 1) % SI;
        qptr->process[qptr->rear] = num1;
        qptr->time[qptr->rear] = num2;
    }
}

void cpu(struct queue *qptr, int q, int n)
{
    int i = qptr->front;
    if (qptr->front == -1 && qptr->rear == -1)
    {
        printf("NO process\n");
    }
    else
    {
        int k = 0;
        while (1)
        {

            for (i = qptr->front; i != qptr->rear + 1; i = (i + 1) % SI)
            {
                if (qptr->time[i] != -999)
                {
                    qptr->time[i] = qptr->time[i] - q;
                    if (qptr->time[i] <= 0)
                    {
                        printf("%d\n", qptr->process[i]);
                        qptr->time[i] = -999;
                    }
                }
            }
            k++;
            if (k == n)
            {
                break;
            }
        }
    }
    printf("\n");
}

int main()
{
    struct queue *qptr;
    struct queue q;
    qptr = &q;
    qptr->front = qptr->rear = -1;
    int num1, num2, n, quantum_time, k;
    printf("Enter no of inputs\n");
    scanf("%d", &n);
    printf("Enter process and excuetion time\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &num1, &num2);
        enqueue(qptr, num1, num2);
    }
    printf("Enter quantum time\n");
    scanf("%d", &quantum_time);
    printf("Enter no of cycles\n");
    scanf("%d", &k);
    printf("Process completed in order:\n");
    cpu(qptr, quantum_time, k);
    return 0;
}
