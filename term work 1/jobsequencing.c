#include<stdio.h>
void jobs(int n,int d[],int p[])
{
int max=0,i,j;
    for(i=0;i<n;i++)
    {
        if(d[i]>max&d[i]<n+1)
        {
            max=d[i];
        }
    }
    int a[max];
     for (i = 0; i < max; i++)
      a[i] = 0;
     for(i=0;i<n;i++)
     {
         for(j=max-1;j>=0;j--)
         {
             if(a[j]==0& j<=d[i]-1)
             {
                 a[j]=i+1;
                 break;
             }
         }
     }
   printf("The jobs which can be performed in the given deadline and its sequence:\n");
      for(i=0;i<max;i++)
      {
          printf("Job%d ",a[i]);
      }
}
int main()
{
    int p[10],d[10],n,i,tp,q,k,s,j;
    printf("Enter total no of jobs available: ");
    scanf("%d",&n);
     printf("\nEnter profits in increasing order: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
     printf("\nEnter respective deadlines: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&d[i]);
    }
    jobs(n,d,p);
}
