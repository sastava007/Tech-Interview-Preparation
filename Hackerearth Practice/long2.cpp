#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,n,k,flag=0, i;
    cin>>t;
    while(t--)
    {
       cin>>n>>k;
       int a[n];
       vector<int> v;
       unordered_map<int, pair <int, int> > m;
       for(i=0;i<n;i++)
            cin>>a[i];
       sort(a,a+n,greater<int>());

       for(i=0;i<n;i++)
       {
          auto it=m.find(a[i]);
          if(it!=m.end())
          {
              (it->second.first) += a[i];
              (it->second.second)++;
              if(it->second.first>=k*a[i])
              {
                  v.push_back(it->second.second);
                  flag=1;
              }
          }
          else
          {
                m.insert(make_pair(a[i],make_pair(a[i],1)));
          }

       int im=*max_element(v.begin(),v.end());
        if(flag==0)
        cout<<"-1"<<endl;
       else
        cout<<im<<endl;
    }
}
}
