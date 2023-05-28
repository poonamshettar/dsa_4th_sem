#include<stdio.h>
#include<string.h>
int count(char string[100])
{
    int x = 0;
    while (string[x] != '\0')
    {
        x++;
    }
    return x;
}

void main()
{
    int n,l1,l2,i,j,k,status=1,p1=0,l,l3,m;
    char str[55],p[10],r[10];
    FILE *fp;
    fp=fopen("b.txt","r+");
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter pattern to be found");
    scanf("%s",p);
    printf("Enter replace: ");
    scanf("%s",r);
    l2=count(p);
    l3=count(r);
     for(int k=0;k<n;k++)
    {   l=ftell(fp);
        fgets(str,50,fp);
        l1=count(str);

        for(i=0;i<l1-l2;i++)
        {
            for(j=0;j<l2;j++)
            {
               if( str[i+j]!=p[j])
                {
                    status=0;
                    break;
                }
            }
            if(j==l2&&status==1)
            {
                p1=1;
                break;
            }
            status=1;
        }
        if(p1==1)
        {
            printf("%s",str);
            m=ftell(fp);
            fseek(fp,-(ftell(fp)-l-i),SEEK_CUR);
            fprintf(fp,"%s",r);
            rewind(fp);
            fseek(fp,m,SEEK_SET);
        }
        p1=0;

    }

}

