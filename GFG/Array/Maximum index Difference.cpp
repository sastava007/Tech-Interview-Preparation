/*
    Here we are finding max(j-1) such that a[i]<=a[j], which means that all the elements before i is greater than a[j] and all the elements after j is smaller than a[i] which means they are of no use
    Make minA: to store min elements so far from L->R
    Make maxA: to store max elements so far from R->l
    Now traverse from L-R and if a[i]<=a[j] then we already got one diff but it may be not maximum so keep incrementing j to find the maximum difference
    Now once a[i]>a[j], then incre i. So now we know than this a[i] will be smaller than previous a[i] becz of minA[] property so this gurantees that a[j] can be found will be found after prev j 
*/



#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[10000001], minA[10000001], maxA[10000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j,ans=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(i!=0)
                minA[i]=min(a[i], minA[i-1]);
            else
                minA[i]=a[i];
        }

        maxA[n-1]=a[n-1];
        for(i=n-2; i>=0;i--)
        maxA[i] = max(a[i], maxA[i+1]);
        i=0,j=0;
        while(i<n && j<n)
        {
            if(minA[i]<=maxA[j])
            {
                ans=max(ans, j-i);
                j++;
            }
            else
                i++;
        }
        cout<<ans<<"\n";    
    }

    return 0;
}