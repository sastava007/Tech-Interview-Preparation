#include<bits/stdc++.h>
using namespace std;
int binary_sch(long long int a[],int ele,int low,int high)
{
    int res;
    while(low<=high)
    {
        res=high;
        int mid=(low+high)/2;
        if(a[mid]==ele)
        {
            res=mid;
            low=mid+1;
        }
        else if(ele>a[mid])
        {
            high=mid-1;
            res=high;
        }
        else if(ele<a[mid])
        low=mid+1;
    }
    return res;
}
main()
{
    long long int a[]={17,6,3,3,3,2,2,2,1};
    cout<<binary_sch(a,20,0,8);
//    int n,i,q,ele;
//    cin>>n;
//    int a[n];
//    for(i=0;i<n;i++)
//    cin>>a[i];
//    sort(a,a+n);
//    cin>>q;
//    while(q--)
//    {
//        cin>>ele;
//        cout<<bubble(a,ele,0,n-1)+1<<endl;
//    }
}
