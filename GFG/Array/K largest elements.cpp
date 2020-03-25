/*
    K largest/smallest element can be solved using Min/max heap respectively 
    and they can be implemented using priority_queue() STL
    Time complexity O(K + (N-K)logK + K) last K can be ignored as k+k =~ K
    Space: O(K)

*/

#include<bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<"\n"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,i,x;
        cin>>n>>k;
        //min priority queue
        priority_queue<int, vector<int>, greater<int>> p;
        for(i=0;i<n;i++)
        {
            cin>>x;
            // deb(x);
            if(p.size()<k)
            p.push(x);
            else if(p.top()<x)
            {
            	// deb(p.top());
                p.pop();
                p.push(x);
            }
        }
        vector<int> ans;
        while(!p.empty())
        {
            ans.push_back(p.top());
            p.pop();
        }
        for(auto it=ans.rbegin();it!=ans.rend();it++)
        cout<<*it<<" ";
        cout<<"\n";
    }
    return 0;
}