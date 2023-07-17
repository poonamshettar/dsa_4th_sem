#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void read(int m,int n,int a[m][n],FILE *fp)
{
srand(time(NULL));
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
a[i][j]=rand()%100;
fprintf(fp,"%d ",a[i][j]);
printf("%d ",a[i][j]);
}
printf("\n");
}
}
void disp(int m,int n,int b[n][m])
{
    int i,j;
for(i=0;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        printf("%d ",b[i][j]);
    }
    printf("\n");
}
}

void transpose(int m,int n,int a[m][n])
{
    int b[n][m];
    for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        b[j][i]=a[i][j];
    }
}
disp(m,n,b);

}
void main()
{
int m,n,i,j;
printf("Enter m and n");
scanf("%d%d",&m,&n);
int a[m][n];
int b[n][m];
FILE *fp=fopen("t.txt","w+");
read(m,n,a,fp);
printf("Transpose :\n");
transpose(m,n,a);
}
