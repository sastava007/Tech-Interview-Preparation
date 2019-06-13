#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,n,i,max_ele,ele,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        max_ele=0;
        vector<long long int> a,b;
        for(i=0;i<n;i++)
        {
            cin>>ele;
            a.push_back(ele);
        }

        for(i=0;i<n;i++)
        {
            cin>>ele;
            b.push_back(ele);
        }
        for(i=0;i<n;i++)
        {
            j=n-1-(lower_bound(b.rbegin(),b.rend(),a[i])-b.rbegin());
            if(j!=-1)
            max_ele=max(max_ele,j-i);
        }
        cout<<max_ele<<endl;
    }
}
