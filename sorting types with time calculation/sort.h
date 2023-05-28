void bubble_sort(int n, int a[n])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n -i- 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int n,int a[])
{
    int min, temp;
    for (int i = 0; i < n-1; i++)
    { min=i;
        for (int j = i+1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min=j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }

}

