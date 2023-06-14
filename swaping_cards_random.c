#include<stdio.h>
void swap(int n ,int a[n])
{ int temp;
   for(int i=0;i<n;i++)
    {
        int r=rand()%n;
        temp=a[r];
        a[r]=a[i];
        a[i]=temp;
    }
}
void disp(int n,int a[n])
{
 for(int i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}
void main()
{   int a[52],r,temp,i=0;
    srand(time(NULL));
    FILE *fp=fopen("ev.txt","r");
    printf("Enter the cards to be swapped : \n");
    while(!feof(fp))
    {
        fscanf(fp,"%d",&a[i]);
        i++;
    }
    disp(52,a);
    printf("\n");
    swap(52,a);
    printf("Cards after swapping : \n");
    disp(52,a);

}
