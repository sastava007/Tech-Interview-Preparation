/*
    Here we are supposed to find consecutive smaller or equal to element on left which is equivalent to => nearest greater element on left.
    https://practice.geeksforgeeks.org/problems/stock-span-problem/0
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

int main()
{

    IOS;
    int t,i;
    cin>>t;
    while (t--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        stack<int> s;
        vector<int> ans;

        for(i=0;i<n;i++)
        {
            if(s.empty())
            {
                s.push(i);
                ans.pb(-1);
            }
            else if(a[s.top()]>a[i])
            {
                ans.pb(s.top());
                s.push(i);
            }
            else
            {
                while (!s.empty() && a[s.top()]<=a[i])
                {
                   s.pop();
                }
                if(s.empty())
                {
                    ans.pb(-1);
                    s.push(i);
                }
                else
                {
                    ans.pb(s.top());
                    s.push(i);
                }
            }
        }
        for(i=0;i<n;i++)
            cout<<i-ans[i]<<" ";
        cout<<"\n";
    }
    
    return 0;
}