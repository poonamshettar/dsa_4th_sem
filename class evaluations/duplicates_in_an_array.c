#include<stdio.h>
void random()
{
    FILE *fp=fopen("a.txt","w");
    for(int i=0;i<20;i++)
    {
        fprintf(fp,"%d ",rand()%10);
    }
    rewind(fp);
    fclose(fp);
}
void read(int a[20])
{  FILE *fp=fopen("a.txt","r");
    for(int i=0;i<20;i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
}
void disp(int a[20])
{
    for(int i=0;i<20;i++)
    {
        printf("%d ",a[i]);
    }
}

void duplicate(int a[20])
{
    int count,i,j;
    for(i=0;i<20;i++)
    {
        count=1;
        if(a[i]==-1)
        {
            continue;
        }
        for(j=i+1;j<20;j++)
        {
            if(a[i]==a[j])
            {
            count++;
            a[j]=-1;
        }
        }
        if(count>1)
        {
            printf("%d->%d\n",a[i],count);
        }

    }

}

void main()
{
    int a[20];
    random();
    read(a);
    disp(a);
    printf("\n");
    duplicate(a);
}

