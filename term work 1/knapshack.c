#include<stdio.h>
#include<stdlib.h>
int main()
{
    int p[10],w[10],n,i,j,max;
    float u[10],temp,x[10],tp=0;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter max: ");
    scanf("%d",&max);
    printf("Enter profits: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter weights");
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    for(i=0;i<n;i++)
    {
        u[i]=(float)p[i]/(float)w[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(u[j]<=u[i])
            {
                temp=u[i];
                u[i]=u[j];
                u[j]=temp;


                temp=p[i];
                p[i]=p[j];
                p[j]=temp;


                temp=w[i];
                w[i]=w[j];
                w[j]=temp;
            }
        }
    }
    printf("\nThe profits per weight in sorted order :\n");
    for(i=0;i<n;i++)
    {
        printf("%0.2f ",u[i]);
    }
    for (i = 0; i < n; i++)
      x[i] = 0.0;

    for(i=0;i<n;i++)
    { if(w[i]>max)
    {
        break;
    }
      x[i]=1.0;
      tp=tp+(float)p[i];
      printf("\n%0.2f ",tp);
      max=max-w[i];
    }
   if (i < n)
      x[i] = max / (float)w[i];
      tp = tp + (x[i] * (float)p[i]);

   printf("\nThe result is: ");
   for (i = 0; i < n; i++)
      printf("%0.2f ", x[i]);

   printf("\nMaximum profit is: %0.3f", tp);
}
