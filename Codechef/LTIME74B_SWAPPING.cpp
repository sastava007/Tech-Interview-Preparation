#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<<"\n";

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        ll index[n],value[n];

        //vector<pair<int,ll>> v;
        ll temp[n];
        for(i=0;i<n;i++)
        {
            index[i]=i+1;
            cin>>value[i];

            //v.emplace_back(make_pair(i+1,temp));
        }
        for(i=0;i<n-1;i++)
        {
            ll t1=index[i]*value[i]+index[i+1]*value[i+1];
            ll t2=index[i]*value[i+1]+index[i+1]*value[i];
            temp[i]=t2-t1;
            // deb(temp[i]);
        }
        temp[i]=temp[i-1];

        //sort(v.begin(),v.end(),compare);
        for(i=0;i<n;)
        {
            if(temp[i]>=temp[i+1])
            {
                swap(value[i],value[i+1]);
                i+=2;
            }
            else
                i++;
        }

        ll sum=0;
        for(i=0;i<n;i++)
            sum+=(index[i]*value[i]);
        cout<<sum<<"\n";


    }
}

