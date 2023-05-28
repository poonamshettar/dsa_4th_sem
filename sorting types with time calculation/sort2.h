  void sort1(int a[],int lb,int ub)
{
    int loc;
    if(lb<ub)
    {
    loc=sort(a,lb,ub);
    sort1(a,lb,loc-1);
    sort1(a,loc+1,ub);
    }

}

int sort(int a[],int lb,int ub)
{  int start,end,piv,temp1,temp2;
    piv=a[lb];
    start=lb;
    end=ub;
    while(start<end)
    {
        while(a[start]<=piv)
        {
            start++;
        }
        while(a[end]>piv)
        {
            end--;
        }
        if(start<end)
    {
         temp1=a[start];
        a[start]=a[end];
        a[end]=temp1;
    }
    }
    temp2=a[lb];
    a[lb]=a[end];
    a[end]=temp2;
    return end;
}

