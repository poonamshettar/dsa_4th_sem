#include<stdio.h>
void main()
{ int n,amt,i,j;
    printf("enter no of coins: ");
    scanf("%d",&n);
    int coin[n];
    printf("Enter the total amount required: ");
    scanf("%d",&amt);
    int a[n][amt+1];
    printf("Enter the denominations of coins: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&coin[i]);
    }
    for(i=0;i<amt+1;i++)
    {
        a[0][i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<=amt;j++)
        {
            if(coin[i]>j)
            {
                a[i][j]=a[i-1][j];
            }
            else
            {
                a[i][j]=a[i-1][j]+a[i][j-coin[i]];
            }
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<amt+1;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\nThe number of ways total amount %d can be obtained is in %d ways",amt,a[n-1][amt]);
}
