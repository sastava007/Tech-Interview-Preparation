#include<bits/stdc++.h>
#define ll long long
#pragma gcc optimize("ofast")
using namespace std;

/*
    * Choose one element as pivot element
    * Make a partition in array with two regions one which contains element smaller than pivot and other which are greater
    * Finally place the pivot at its appropriate position
    * And call quicksort on left and right region of pivot element
*/

void shuffle(ll *a, int s, int e)
{
    // to randomly shuffle all the elements of array on each run
    srand(time(NULL));
    for(int i=e;i>0;i--)
    {
        int j=rand()%i;
        swap(a[i],a[j]);
    }
}

int partition(ll *a, int s, int e)
{
    ll pivot=a[e];
    int i=s-1;
    int j=s;
    for(;j<e;j++)
    if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    // bring pivot element back to its original position
    swap(a[i+1],a[e]);
    return i+1;
}

void quicksort(ll *a, int s, int e)
{
    if(s>=e)
        return;

    int p=partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);


}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    shuffle(a,0,n-1);
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

