#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,i;
    cin>>n;
    int a[n];
    vector<int> s;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s.push_back(a[i]);
    }
    for(int i=0;i<s.size();i++)
    {
       auto m=find(s.begin(),s.end(),a[i])-s.end();
       cout<<m<<" ";
       s.delete(m);
    }


}
