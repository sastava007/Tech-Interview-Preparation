#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,m,i,j,temp,flag;
    cin>>n;
    set<int> a;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        a.insert(temp);
    }
    cin>>m;
    set<int> c;
    for(j=0;j<m;j++)
    {
        cin>>temp;
        c.insert(temp);
    }
    set<int> b;
    for(auto it=a.begin();it!=a.end();it++)
        for(auto jt=c.begin();jt!=c.end();jt++)
    {
        flag=0;
        temp=*jt-*it;
        for(auto kt=a.begin();kt!=a.end();kt++)
        {
            if(c.find(temp+ *kt)==c.end())
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            b.insert(temp);
    }
    for(auto it=b.begin();it!=b.end();it++)
        cout<<*it<<" ";
}
