/*
    Very useful concept, and this is the base problem for all the further variations.

    So basically, idea is to maintain a deque that stores all the useful elements, a element is useful if it lies in current winodw and is is greater than all all elements on its left
    In this way, we end up with maximum element of each window at front of queue.

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
    // IOS;    
    int t,i;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        deque<ll> q;
        
        for(i=0;i<k;i++)    
        {
            while(!q.empty() && a[i]>=a[q.back()])
                q.pop_back();

            q.push_back(i);
        }
        
        for(i=k;i<n;i++)
        {
            cout<<a[q.front()]<<" ";

            //remove elements outside of this window
            while (!q.empty() && q.front()<(i-k+1))
                q.pop_front();

            //remove element which are not useful, i.e elements which are less than current element
            while (!q.empty() && (a[i]>=a[q.back()]))
                q.pop_back();

            q.push_back(i);
        }
        cout<<a[q.front()]<<"\n";
        
    }
    
    
    return 0;
}