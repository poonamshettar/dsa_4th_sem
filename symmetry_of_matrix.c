#include<stdio.h>
#include<time.h>
void read(int m,int n,int a[m][n])
{
    FILE *fp=fopen("b.txt","r");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            fscanf(fp,"%d ",&a[i][j]);
        }
    }
}

void disp(int m,int n,int a[m][n])
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

void transpose(int m,int n,int a[m][n])
{
    int b[m][n],i,j,p=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            b[j][i]=a[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                printf("Not symmetric");
                exit(0);
            }
            p++;
        }
    }
    if(p==m*n)
    {
        printf("Symmetric");
    }
}


void main()
{
    int n,m,start,stop;
    printf("Enter m and n:\n");
    scanf("%d%d",&m,&n);
    int a[m][n];
    if(m!=n)
    {
        printf("Rows not equals column not symmetric");
        exit(0);
    }
    read(m,n,a);
    start=clock();
    disp(m,n,a);
    transpose(m,n,a);
    stop=clock();
    float time_r = (float)(stop - start) / CLOCKS_PER_SEC;
    printf("\nTime: %f\n",time_r);
    printf("\nThe transposed matrix\n");
    disp(m,n,a);

}
