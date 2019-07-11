#include<bits/stdc++.h>
using namespace std;

bool issorted(int *a,int n)
{
    if(n==1)
        return true;
    if(a[0]<a[1] && issorted(a+1,n-1))
        return true;
    else
        return false;

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n=5;
    int a[]={1,2,3,5,7};
    cout<<issorted(a,n);

}
