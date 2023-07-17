#include<stdio.h>
int length(char str[100],int i)
{
     if(str[i]=='\0')
{
    return;
}

else
{
    return 1+length(str,i+1);
}
}

void main()

{
    char str[100];
    int p;
    printf("Enter string : ");
    gets(str);
    p=length(str,0);
    printf("\nThe length of the string is : %d ",p);
}
