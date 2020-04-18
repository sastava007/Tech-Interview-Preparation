/*
    This is a variation of problem, finding Maximum of All Subarrays of Size K.
    Here also we'll use deque to store useful elements of current window, an element is useful if it's negative and lies in current window.

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
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        cin>>k;
        queue<int> q;

        //process elements of first window
        for(i=0;i<k;i++)
            if(a[i]<0)
            q.push(i);
        
        for(i=k;i<n;i++)
        {
            !q.empty()?cout<<a[q.front()]<<" ":cout<<"0 ";
            
            // remove the elements which are out of this window.
            while(!q.empty() && q.front()<(i-k+1))
                q.pop();
            if(a[i]<0)
                q.push(i);
        }
        !q.empty()?cout<<a[q.front()]<<" ":cout<<"0 ";
        cout<<"\n";
    }
    
    return 0;
}