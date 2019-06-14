
#include<bits/stdc++.h>
using namespace std;
void solve(int a[],int low,int high)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        cout<<a[mid]<<"\n";
        solve(a,low,mid-1);
        solve(a,mid+1,high);

    }
    else
    return;
}
main()
{

    int n,i;
    int a[7]={2, 4, 1, 3, 5, 6, 7};
    sort(a,a+7);
    solve(a,0,6);

}
