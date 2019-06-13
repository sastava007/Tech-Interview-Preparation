#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i,c=1;
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n,greater<int>());
    long long int s=a[0],max_sum=a[0];
    for(i=1;i<n;i++)
    {
        s+=a[i];
        if(s>max_sum)
        {
            max_sum=s;
            c++;
        }
        else
        break;
    }
    cout<<max_sum<<" "<<c;
}
