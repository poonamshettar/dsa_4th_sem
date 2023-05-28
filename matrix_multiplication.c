#include<stdio.h>
void random(FILE *fp)
{
  for(int i=0;i<20;i++)
  {
      fprintf(fp,"%d ",rand()%10);
  }
}
void read(int a[100][100],int m,int n,FILE *fp)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            fscanf(fp,"%d",&a[i][j]);
        }
    }
}

void disp(int a[100][100],int m,int n)
{
   for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void mult(int a[100][100],int b[100][100],int m1,int n1,int m2,int n2)
{
    int mul[100][100],j,sum;
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n2;j++)
        { int sum=0;
            for(int k=0;k<n1;k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            mul[i][j]=sum;
            printf("%d ",mul[i][j]);
        }
        printf("\n");
    }
}
void main()
{
  int m1,n1,m2,n2,a[100][100],b[100][100],sum[100][100];
  printf("Enter m1 and n1");
  scanf("%d%d",&m1,&n1);
  printf("Enter m2 and n2");
  scanf("%d%d",&m2,&n2);
  FILE *fp=fopen("b.txt","w+");
  random(fp);
  rewind(fp);
  read(a,m1,n1,fp);
  read(b,m2,n2,fp);
  disp(a,m1,n1);
  disp(b,m2,n2);
  mult(a,b,m1,n1,m2,n2);

  return 0;
}
