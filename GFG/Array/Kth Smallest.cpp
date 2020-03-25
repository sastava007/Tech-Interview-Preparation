// Kth smallest element using counting sort O(N+K), where K is range
#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
        //here we are using min & max element for dealing with negative numbers and build the range.
        int n,k,i,minE=INT_MAX,maxE=INT_MIN;
        cin>>n;
        int a[n], out[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            minE = min(minE, a[i]);
            maxE = max(maxE, a[i]);
        }
        cin>>k;
        int range = maxE-minE+1;
        int count[range]={0};
        for(i=0;i<n;i++)
        count[a[i]-minE]++;
    
        for(i=1;i<range;i++)
            count[i]+=count[i-1];
    
        //produce the output array
        for(i=0;i<n;i++)
        {
            out[count[a[i]-minE]-1]=a[i];
            count[a[i]-minE]--;
        }
        cout<<out[k-1]<<"\n";
    }
    
    
    return 0;
}


//Kth largest element using minheap O(K+ (n-k)logK)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
     
        priority_queue<int, vector<int>, greater<int>> p;
        for(auto it: nums)
        {
            if(p.size()<k)
                p.push(it);
            else if(it>p.top())
            {
                p.pop();
                p.push(it);
            }
        }
        return p.top();
    }
};