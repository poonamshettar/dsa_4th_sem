#include <stdio.h>
#include <string.h>

void pattern(char str[55], char p[10], FILE *fp)
{
    int status = 1, p1 = 0, l1, l2,j,i ;
    while (!feof(fp))
    {
        fgets(str, 50, fp);
        l1 = strlen(str);
        l2 = strlen(p);

        for (i = 0; i < l1 - l2; i++)
        {
            for (j = 0; j < l2; j++)
            {
                if (str[i + j] != p[j])
                {
                    status = 0;
                    break;
                }
            }
            if (j == l2 && status == 1)
            {
                p1 = 1;
                break;
            }
            status = 1;
        }
        if (p1 == 1)
        {
            printf("%s", str);
        }
        p1 = 0;
    }
}

void main()
{
    int n, l1, l2, i, j, k, status = 1, p1 = 0;
    char str[55], p[10];
    FILE *fp;
    fp = fopen("b.txt", "r");
    printf("Enter pattern to be found: ");
    scanf("%s", p);
    printf("\nThe lines with the required pattern: \n");
    pattern(str, p, fp);
}
