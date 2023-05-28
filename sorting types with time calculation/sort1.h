void merge(int a[],int lb,int mid,int ub)
{ int i,j,k,n1,n2;
  n1=mid-lb+1;
  n2=ub-mid;
  int p[n1],q[n2];
    for(i=0;i<n1;i++)
    {
        p[i]=a[lb+i];
    }
    printf("\n");
    for(i=0;i<n2;i++)
    {
        q[i]=a[mid+1+i];
    }
    printf("\n");
    i=0,j=0,k=lb;
    while(i<n1&&j<n2)
    {
    if(p[i]<=q[j])
    {
        a[k]=p[i];
        i++;
        k++;
    }
    else
    {
        a[k]=q[j];
        j++;
        k++;
    }
    }

        while(j<n2)
        {
            a[k]=q[j];
            k++;
            j++;
        }
       while(i<n1)
        {
            a[k]=p[i];
            k++;
            i++;
        }
    }

  void merge_sort(int a[],int lb,int ub)
{ int mid;
    if(lb<ub)
    {  mid=(lb+ub)/2;
        merge_sort(a,lb,mid);
        merge_sort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
