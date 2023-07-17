#include<stdio.h>
#include<string.h>
#define size 10
struct queue
{
    char name[20][size];
    int age[size];
    char disease[20][size];
    int rear,front;
};

void enqueue(struct queue *qptr,FILE *fp)
{
  qptr->rear++;
  fscanf(fp,"%s",qptr->name[qptr->rear]);
  fscanf(fp,"%d",&qptr->age[qptr->rear]);
  fscanf(fp,"%s",qptr->disease[qptr->rear]);
}

void sort_age(struct queue *qptr)
{
    int i,j,temp;
    char temp1[20];
    FILE *fp2=fopen("age.txt","w");
    for(i=qptr->front+1;i<=qptr->rear;i++)
    {
        for(j=i;j<=qptr->rear+1;j++)
        {
            if(qptr->age[i]<qptr->age[j])
            {
                temp=qptr->age[i];
                qptr->age[i]=qptr->age[j];
                qptr->age[j]=temp;

                strcpy(temp1,qptr->name[i]);
                strcpy(qptr->name[i],qptr->name[j]);
                strcpy(qptr->name[j],temp1);

                strcpy(temp1,qptr->disease[i]);
                strcpy(qptr->disease[i],qptr->disease[j]);
                strcpy(qptr->disease[j],temp1);
            }
        }
    }
    disp(qptr,fp2);
    fclose(fp2);
}

void sort_disease(struct queue *qptr)
{
    struct queue *pptr;
    struct queue p[10];
    pptr=p;
    FILE *fp1=fopen("disease.txt","w");
    pptr->rear=pptr->front=-1;
    int i,a;
    char priority[20];
    printf("Enter the disease which needs to be consulted first: ");
    scanf("%s",priority);
 for(i=qptr->front+1;i<=qptr->rear;i++)
    {
      if(strcmp(qptr->disease[i],priority)==0)
      {
          pptr->rear++;
          strcpy(pptr->name[pptr->rear],qptr->name[i]);
          strcpy(pptr->disease[pptr->rear],qptr->disease[i]);
          pptr->age[pptr->rear]=qptr->age[i];
      }
    }
    for(i=qptr->front+1;i<=qptr->rear;i++)
    {
      if(strcmp(qptr->disease[i],priority)!=0)
      {
           pptr->rear++;
          strcpy(pptr->name[pptr->rear],qptr->name[i]);
          strcpy(pptr->disease[pptr->rear],qptr->disease[i]);
          pptr->age[pptr->rear]=qptr->age[i];
      }
    }
    printf("The list after prioritised by any emergency disease:\n");
    disp(pptr,fp1);
    fclose(fp1);
  printf("\n");
    while(1)
 {
     printf("Enter 1 if the 1st patient in list gets his appointment done");
     scanf("%d",&a);
     if(a==1)
     {
     dequeue(pptr);
     printf("\n");
     }
 }
}

void dequeue(struct queue *pptr)
{
  FILE *fp3=fopen("updated.txt","w");

  pptr->front++;
  disp(pptr,fp3);
  fclose(fp3);
}

void disp(struct queue *qptr,FILE *fp1)
{int i;
if(qptr->rear==qptr->front)
  {
      printf("Patient list is empty\n");
      exit(0);
  }
    for(i=qptr->front+1;i<=qptr->rear;i++)
    {
        printf("%s ",qptr->name[i]);
        printf("%d ",qptr->age[i]);
        printf("%s\n",qptr->disease[i]);
        fprintf(fp1,"%s ",qptr->name[i]);
        fprintf(fp1,"%d ",qptr->age[i]);
        fprintf(fp1,"%s\n",qptr->disease[i]);

    }
}
void main()
{
 struct queue *qptr;
 struct queue q[10];
 qptr=q;
 int n,i,a;
 qptr->rear=qptr->front=-1;
 printf("Enter number of patients:");
 scanf("%d",&n);
 FILE *fp=fopen("details.txt","r");
 for(i=0;i<n;i++)
 {
 enqueue(qptr,fp);
 }
 printf("The initial patient details :\n");
 disp(qptr,fp);
 printf("\n");
 printf("\nThe patients list after prioritised by their age:\n");
 sort_age(qptr);
 printf("\n");
 sort_disease(qptr);

}
