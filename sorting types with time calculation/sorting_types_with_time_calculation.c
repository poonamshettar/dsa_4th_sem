#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "sort.h"
#include "sort1.h"
#include "sort2.h"
void random(int n,FILE *fp)
{ int max,min,n1;
 printf("Enter max and min");
  scanf("%d%d",&max,&min);
     for(int i=0;i<n;i++)
{
   n1=(rand()%(max-min+1))+min;
   fprintf(fp,"%d ",n1);
}
}

void read(int a[],int n,FILE *fp)
{
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&a[i]);
    }
}

void disp(int a[],int n,FILE *fp)
{
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d ",a[i]);
    }
}
void compute(int a[],int n,FILE *fp1)
{
  rewind(fp1);
  read(a,n,fp1);
}

void t(int a[],int n,FILE *fp1)
{
  int start,stop;
  FILE *fp2=fopen("output.txt","w");
  FILE *fp3=fopen("log.txt","w");
  start=clock();
  bubble_sort(n,a);
  stop=clock();
  float time_r = (float)(stop - start) / CLOCKS_PER_SEC;
  fprintf(fp3,"%f ",time_r);
  compute(a,n,fp1);
  start=clock();
  selection_sort(n,a);
  stop=clock();
  time_r = (float)(stop - start) / CLOCKS_PER_SEC;
  fprintf(fp3,"%f ",time_r);
  disp(a,n,fp2);
  compute(a,n,fp1);
  start=clock();
  merge_sort(a,0,n-1);
  stop=clock();
  time_r = (float)(stop - start) / CLOCKS_PER_SEC;
  fprintf(fp3,"%f ",time_r);
  compute(a,n,fp1);
  start=clock();
  sort1(a,0,n-1);
  stop=clock();
  time_r = (float)(stop - start) / CLOCKS_PER_SEC;
  fprintf(fp3,"%f ",time_r);


}

int main()
{
    int n;
    printf("Enter n");
    scanf("%d",&n);
    int a[n];
    FILE *fp1=fopen("input.txt","w+");
    random(n,fp1);
    rewind(fp1);
    read(a,n,fp1);
    //disp(a,n);
    t(a,n,fp1);

}
