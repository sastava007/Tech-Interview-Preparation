#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,i,j;
  cin>>n;
  vector<int> a(n);
  int s[n];
  for(i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    for(i=0;i<n;i++)
    {
        int l=lower_bound(a.begin(),a.end(),a[i])-a.begin();
        int r=lower_bound(a.end(),a.begin(),a[i])-a.end();
        cout<<l<<" "<<r<<"\n";
        s[i]=fabs(l-r)+1;
    }

    cout<<accumulate(s,s+n,0);
  return 0;
}
