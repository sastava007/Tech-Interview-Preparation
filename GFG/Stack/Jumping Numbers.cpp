#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

set<ll> s;
void jumpingNumbers(ll n)
{
    //clear all the elments of previous test case
    s.clear();
    s.insert(0);
    queue<ll> q;
    for(int i=1;i<=9;i++)
    {
        q.push(i);
        while(!q.empty())
        {
            ll temp=q.front();
                q.pop();
                
            if(temp>n)
                continue;
            s.insert(temp);
            int rightMost=temp%10;
            if(rightMost>0)
                q.push(temp*10+rightMost-1);
            if(rightMost<9)
                q.push(temp*10+rightMost+1);
        }
    }
}
int main()
{
    // IOS;    
    int t,i;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        jumpingNumbers(n);

        for(auto it:s)
            cout<<it<<" ";
        cout<<"\n";

    }
    
    return 0;
}