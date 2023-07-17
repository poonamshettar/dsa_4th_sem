#include <stdio.h>

void towerOfHanoi(int n, char s, char d, char a)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", s, d);
        return;
    }

    towerOfHanoi(n - 1, s, a, d);
    printf("Move disk %d from %c to %c\n", n, s, d);
    towerOfHanoi(n - 1, a, d, s);
}

int main()
 {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}

