#include<stdio.h>
int count(char str[10])
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }
    return i;
}
void swap(char *c, char *d)
{
    char temp;
    temp = *c;
    *c = *d;
    *d = temp;
}

void permutation(char *a ,int l, int r)
{
    int i;
    if(l==r)
    {
        printf("%s\n",a);
    }
    else
    {
        for(i=l;i<=r;i++)
        {
            swap((a+l),(a+i));
            permutation(a,l+1,r);
            swap((a+l),(a+i));
        }
    }
}

void main()
{
    char a[10];
    printf("Enter string: ");
    scanf("%s",a);
    printf("The permutations of the given string are:\n");
    permutation(a,0,count(a)-1);
}
