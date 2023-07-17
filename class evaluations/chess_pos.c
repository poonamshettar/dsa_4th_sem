#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void disp(char c[8][8][10])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%-10s ", c[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    char c[8][8][10], ch[10];
    int i, j, pos, s = 0, k;
    FILE *fp = fopen("chess.txt", "r");
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            fscanf(fp, "%s", c[i][j]);
        }
    }
    disp(c);
    while (1)
    {
       s=0;
        printf("Enter coin to be moved");
        scanf("%s", ch);
        printf("Enter pos it has to be moved");
        scanf("%d", &pos);

        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
            {
                if (strcmp(c[i][j], ch) == 0)
                {

                        s = 1;
                        if(strcmp(c[i+1][j],"0")==0)
                        {
                          strcpy(c[i][j], "0");
                        for (k = i; k < i+pos; k++)
                            ;
                        strcpy(c[k][j], ch);
                        }
                        else
                        {
                        printf("Cant move\n");
                        }
                        break;

                }
            }
            if (s == 1)
            {
                break;
            }
        }
        disp(c);
    }
}
