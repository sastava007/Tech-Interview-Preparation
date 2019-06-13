#include<bits/stdc++.h>
using namespace std;
void solve(string s,int n)
{
    int i,no_of_replace=0,no_of_a=0;
    if(s[0]=='a')
    no_of_a++;

    for(i=1;i<n-1;i++)
    {
        if(s[i]=='v'&&s[i-1]=='v')
        {
            cout<<"No\n";
            return;
        }
        if(s[i]=='a')
        no_of_a++;
        if(s[i]=='a' &&s[i-1]!='v'&&s[i+1]!='v')
        no_of_replace++;

    }
    if((n!=1&&no_of_replace==0) || no_of_a==1)
    {
        cout<<"No\n";
        return;
    }
    else
    cout<<"Yes\n";
    return;

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        solve(s,n);
    }
}
