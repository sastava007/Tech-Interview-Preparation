#include<bits/stdc++.h>
using namespace std;
int bsearch(set<int> *a,int low,int high)
main()
{
    int n,q,i,i1,i2;
    cin>>n>>q;
    string a,b;
    cin>>a>>b;
    set<int> a1;
    set<int> b1;
    for(i=0;i<n;i++)
    {
        if(a[i]=='1')
            a1.insert(i);
        if(b[i]=='1')
            b1.insert(i);
    }
    while(q--)
    {
        cin>>i;
        b1.insert(i);
        while(1)
        {
            i1=a1.lower_bound(a1.begin(),a1.end(),'1')-a1.begin();
            i2=b1.lower_bound(b1.begin(),b1.end(),'1')-b1.begin();
            if(i1>i2)
            {
                cout<<"NO\n";
                break;
            }
            else if(i2>i1)
            {
                cout<<"YES\n";
                break;
            }
        }
    }
}
