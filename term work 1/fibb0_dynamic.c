#include<stdio.h>
void main()
{
    int n,i;
    printf("Enter no of elements of series to be displayed : ");
    scanf("%d",&n);
    int f[n];
    f[0]=0;
    f[1]=1;
    for(i=2;i<n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    printf("The fibonacci series of %d numbers:\n",n);
    for(i=0;i<n;i++)
    {
        printf("%d ",f[i]);
    }
}
