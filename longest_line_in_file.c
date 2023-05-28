#include<stdio.h>
typedef struct st_text
{
    char str[50];
}text;

int count(char st[50])
{
    int p=0,i=0;
    while(st[i]!='\0')
    {
        p++;
        i++;
    }
    return p;
}

int read(text *tptr,FILE *fp)
{
    int n=0;
    while(!feof(fp))
    {
        fgets(tptr->str,40,fp);
        tptr++;
        n++;
    }
    return n;
}

void disp(text *tptr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%s",tptr->str);
        tptr++;
    }
}


int longest(text *tptr,int n)
{
  int p[10],max,m,i;
  for(i=0;i<n;i++)
  {
      p[i]=count(tptr->str);
      tptr++;
  }
  max=0;
  for(i=0;i<n;i++)
  {
      if(p[i]>max)
      {
          max=p[i];
          m=i;
      }
  }

  return m;
}

void main()
{

    text *tptr;
    text t[10];
    tptr=t;
    int n,m,i;
    FILE *fp;
    fp=fopen("b.txt","r+");
    n=read(tptr,fp);
    disp(tptr,n);
     m=longest(tptr,n);
    printf("\nThe longest line\n");
    for(i=0;i<m;i++)
  {
      tptr++;
  }
  printf("%s",tptr->str);

  fprintf(fp,"%s",tptr->str);
}
