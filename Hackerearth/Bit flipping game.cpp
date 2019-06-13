#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(x) push_back(x)
main()
{
   int t,i,n;
   string s;
   cin>>n;
   map<int,int> m;
   while(n--)
   {
       cin>>s;
       for(i=0;i<s.length();i++)
        if(s[i]=='1')
            m[i]++;
        if(m.size()%2)
        {
            cout<<"A\n"<<m.size();
        }
        else
            cout<<"B\n"<<m.size();

   }
}

