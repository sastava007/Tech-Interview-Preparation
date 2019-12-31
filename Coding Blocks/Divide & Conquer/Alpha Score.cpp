#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"
#define mod 1000000007

ll alphaScore=0;
ll mergeArray(ll *a, int low, int high)
{
    int mid=(low+high);
    int i=low,k=low;
    int j=mid+1;

    ll temp[100005];
    ll alphaScore=0;
    while((i<=mid) && (j<=high))
    {
        if(a[i]<a[j])
        {
            alphaScore=(alphaScore%mod+((high-j+1)*a[i])%mod)%mod;
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }

    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=high)
        temp[k++]=a[j++];
    for(int i=low;i<=high;i++)
        a[i]=temp[i];
    return alphaScore;
}


ll mergeSort(ll *a, int low, int high)
{
    if(low>=high)
        return alphaScore;

        int mid=(low+high)/2;
        alphaScore=mergeSort(a,0,mid);
        alphaScore=(alphaScore+ mergeSort(a,mid+1,high))%mod;
        alphaScore=(alphaScore+mergeArray(a,low,high))%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<mergeSort(a,0,n-1);
    return 0;
}
