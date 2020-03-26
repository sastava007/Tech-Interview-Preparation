// In order to calculate sum of a subarray we can use prefix sum which means sum[l-r] = prefixSum[0-r]-prefixSum[0-(l-1)]
// So if this sum is zero then bith prefix will be equal, and I used this property only i.e check when prefixSum[0-r] = prefixSum[0-(l-1)] using hash map

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,ans=0;
        cin>>n;
        int a[n];
        unordered_map<int, int> m;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(i!=0)
            a[i]+=a[i-1];
            m[a[i]]++;
        }
        for(auto it:m)
        {
            if(it.first==0)
            ans += ((it.second*(it.second+1))/2);
            else 
            ans += ((it.second*(it.second-1))/2);
        }
        cout<<ans<<"\n";
    }
    return 0;
}