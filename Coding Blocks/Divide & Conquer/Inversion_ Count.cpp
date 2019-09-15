#include <bits/stdc++.h>
using namespace std;

int merge(int *a, int low, int high)
{
    int mid=(low+high)/2;
    int i=low;
    int inv_count=0;

    int temp[1000];

    int j=mid+1;
    int k=low;
    while((i<=mid) && (j<=high))
    {
        if(a[i]<=a[j])
            temp[k++]=a[i++];
        else
        {
            temp[k++]=a[j++];
            inv_count+=(mid-i+1);
        }
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=high)
        temp[k++]=a[j++];
    for(int i=low;i<=high;i++)
        a[i]=temp[i];
    return inv_count;

}

int mergeSort(int *a, int low, int high)
{
    int inv_count=0;
    if(high>low)
    {
        int mid=(low+high)/2;

        inv_count=mergeSort(a,low,mid);
        inv_count+=mergeSort(a,mid+1,high);
        inv_count+=merge(a,low,high);
    }
    return inv_count;
}


main()
{
    int a[]={ 1, 20, 6, 4, 5 };
    cout<<mergeSort(a,0,4);
}
