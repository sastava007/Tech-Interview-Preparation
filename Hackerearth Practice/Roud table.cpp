#include<bits/stdc++.h>
using namespace std;
main()
{
    int it,n,q,x,y;
    cin>>n>>q;
    int a[n];
    typedef pair<int, int> pairs;
    set<pairs> s1,s2;
    for(it=0;it<n;it++)
    cin>>a[it];
    while(q--)
    {
        cin>>x>>y;
        for(it=0;it<n;it++)
        {
            if(a[it]==x)
            s1.insert(make_pair(it,n-it-1));
            else if(a[it]==y)
            s2.insert(make_pair(it,n-it-1));
        }

        int min_time=n+1;
        for(auto i:s1)
        for(auto j:s2)
        {
            min_time=min(min_time,abs((i.first-j.first)/2));
            if(i.first<j.first)
            {
                min_time=min(min_time,(i.first + j.second)/2);
            }
            else
            {
                min_time=min(min_time,(i.second+j.first)/2);
            }
        }

        cout<<min_time<<endl;
        min_time=n+1;
        s1.clear();
        s2.clear();
    }
}
