/*
    https://practice.geeksforgeeks.org/problems/immediate-smaller-element/0
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

int main()
{

    IOS;

    int t;
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
        for(i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                ans.push_back(-1);
                s.push(a[i]);
            }
            else if(s.top()<a[i])
            {
                ans.push_back(s.top());
                s.pop();
                s.push(a[i]);
            }
            else
            {
                ans.push_back(-1);
                s.push(a[i]);
            }
            
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans)
            cout<<it<<" ";
        cout<<"\n";
    }
    
    return 0;
}