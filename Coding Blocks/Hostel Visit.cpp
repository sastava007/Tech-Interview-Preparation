#include<bits/stdc++.h>
using namespace std;
main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q,k;
    cin>>q>>k;
    long long int t,x,y;
    priority_queue<int,vector<int>,greater<int>> dist;
    long long int distance;
    while(q--)
    {
        cin>>t;
        if(dist.size()==k+1)
            dist.pop_back();
        if(t==1)
        {
            cin>>x>>y;
            distance=x*x + y*y;
            dist.push(distance);
        }

        else
        cout<<dist.back()<<"\n";

    }
}
