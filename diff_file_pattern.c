#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    char str[100],s[20],r[20];
    int l1,l2,status=1,p=0,i,j,k,l3,n,l=0,m,y;
    FILE *fp = fopen("p.txt", "r+");
    FILE *fp1 = fopen("p2.txt","w");
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter search and replace: ");
    scanf("%s\n",s);
    gets(r);
    l2=count(s);
    l3=count(r);
    for(k=0;k<n;k++)
    {   l=ftell(fp);
        fgets(str, 50, fp);
        l1=count(str);
        for(i=0;i<l1-l2;i++)
        {
            for(j=0;j<l2;j++)
            {
                if(str[i+j]!=s[j])
                {
                    status=0;
                    break;
                }
            }
            status=1;
            if(status==1&&j==l2)
            {
                p=1;
                break;
            }

        }
        if(p==1)
        {
            printf("%s",str);
            for(y=0;y<i;y++)
            {
                fprintf(fp1,"%c",str[y]);
            }
            fprintf(fp1,"%s",r);
            for(y=i+l2;y<l1;y++)
            {
                fprintf(fp1,"%c",str[y]);
            }
        }
        p=0;
    }
}
