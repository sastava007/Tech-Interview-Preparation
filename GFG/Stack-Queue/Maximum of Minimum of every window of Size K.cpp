/*
    https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/?ref=rp
    The first two steps are similar to maximum area in histogram problem, but not sure, about the third step.
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
        int n;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];

        stack<int> s1,s2;
        vector<int> nsl(n), nsr(n);

        //finding nearest smaller on left
        for(i=0;i<n;i++)
        {
            if(s1.empty())
                nsl[i]=-1;
            else if(a[s1.top()]<a[i])
                nsl[i]=s1.top();
            else
            {
                while (!s1.empty() && a[s1.top()]>=a[i])
                    s1.pop();
                if(s1.empty())
                    nsl[i]=-1;
                else
                    nsl[i]=s1.top();
            }
            s1.push(i);
        }

        //finding nearest smaller on right
         for(i=n-1;i>=0;i--)
        {
            if(s2.empty())
                nsr[i]=n;
            else if(a[s2.top()]<a[i])
                nsr[i]=s2.top();
            else
            {
                while (!s2.empty() && a[s2.top()]>=a[i])
                    s2.pop();
                if(s2.empty())
                    nsr[i]=n;
                else
                    nsr[i]=s2.top();
            }
            s2.push(i);
        }

        int ans[n+1]={0};
        // a[i] is minimum element in subarray of size len{ nsr[i]-nsl[i]-1}
        for(i=0;i<n;i++)
        {
            int len = nsr[i]-nsl[i]-1;
            ans[len]=max(ans[len], a[i]);
        }

        //fill the remaining empty positions
        for(i=n-1;i>=1;i--)
            ans[i]=max(ans[i], ans[i+1]);

        for (i=1; i<=n ; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        
    }
    
    return 0;
}   