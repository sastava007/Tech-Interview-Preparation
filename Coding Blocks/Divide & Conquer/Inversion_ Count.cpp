#include <bits/stdc++.h>
#define ll long long
#pragma gcc optimize("ofast")
using namespace std;

int merge(ll *a, int low, int high)
{
    int mid=(low+high)/2;
    int i=low;
    int inv_count=0;

    int temp[100009];

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

int mergeSort(ll *a, int low, int high)
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


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
        cin>>a[i];

        cout<<mergeSort(a,0,n-1)<<"\n";
    }
    return 0;

}
