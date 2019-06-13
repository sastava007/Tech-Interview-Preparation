#include <bits/stdc++.h>
using namespace std;
main()
{
    int n,i;
    cin>>n;
    int s[n];
    for(i=0;i<n;i++)
    cin>>s[i];
    sort(s,s+n);
    string a,b;
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        a.insert(i/2,1,s[i]);
        else
        b.insert(i/2,1,s[i]);
    }
    int x=stoi(a);
    int y=stoi(b);
    cout<<x+y<<endl;
}
