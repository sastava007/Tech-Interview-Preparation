#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
   char a[20];
   cin>>a;

   int n=strlen(a),i;
   ll ans=0;
   ans=(1<<n) -2;

   int pos=0;

   for(i=n-1;i>=0;i--,pos++)
   {

       if(a[i]=='7')
        ans+=(1<<pos);
   }
   cout<<ans+1;
}
