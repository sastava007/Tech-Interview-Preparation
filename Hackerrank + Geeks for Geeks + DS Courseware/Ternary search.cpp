#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

int ternarySearch(int low, int high, int *a, int key)
{
    int mid1 = low + (high - low) / 3;
    int mid2 = high - (high - low) / 3;

    if(high>=low)
    {
        if(key==a[mid1])
            return mid1;
        if(key==a[mid2])
            return mid2;

        if(key<a[mid1])
            return ternarySearch(low, mid1-1, a, key);
        else if(key>a[mid2])
            return ternarySearch(mid2+1, high, a, key);
        else
            return ternarySearch(mid1+1, mid2-1, a, key);
    }
    return -1;
}

main()
{
    int i,n=25000;
    int a[n];
    for(int i=0;i<n;i++)
    {
        srand(time(NULL));
        a[i]=rand();
    }
    sort(a,a+n);
    int t;

    for(auto it:a)
    
    cout<<"Enter no. of test cases: ";
    cin>>t;
    while(t--)
    {
        srand(time(NULL));
        int k=rand();
        cout<<ternarySearch(0,n-1,a,k)<<"\n";

    }
}
