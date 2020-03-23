/*
 Unlike other problems where we use two pointers over given array, here we are using two pointer over sum pair. 
 Time Complexity O(n2)
*/

#include<bits/stdc++.h>
using namespace std;
int a[100001];

bool compare(pair<int,int> &p, pair<int,int> &q)
{
    return a[p.first]+a[p.second] < a[q.first]+a[q.second];
}
bool isNotEqual(int a, int b, int p, int q)
{
    return (a!=p && a!=q && b!=p && b!=q);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j,k;
        bool found = false;
        cin>>n;
        vector<pair<int, int>> v;
        for(i=0;i<n;i++)
            cin>>a[i];
        cin>>k;
        for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            v.push_back({i,j});
        sort(v.begin(), v.end(), compare);
        int l=0,r=v.size()-1;
        while(l<r)
        {
            int sum = a[v[l].first]+a[v[l].second]+a[v[r].first]+a[v[r].second];
            if(sum == k && isNotEqual(v[l].first, v[l].second, v[r].first, v[r].second))
            {
                found=true;
                break;
            }
            else if(sum<k)
            l++;
            else
            r--;
        }
        found?cout<<"1\n":cout<<"0\n";
        
    }
    return 0;
}


/*
Here I have used hashing with multimap, which would ideally runs in O(n2).
But if there are more collisions i.e more sum pair with same value then it would rise to O(n4), becz total n2 sum pairs can have same value

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
	    ll n,i,k,j;
        bool found=false;
	    cin>>n;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        cin>>k;

        // becz there can be same sum as key
        unordered_multimap<ll, pair<ll,ll>> m;
        for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            m.insert({a[i]+a[j], {i,j}});
    
        for(i=0; i<n-1 && !found; i++)
        for(j=i+1; j<n && !found; j++)
        {
            ll sum=a[i]+a[j];
            auto it = m.find(k-sum);
            if(it!=m.end())
            {
                for(; it->first==(k-sum); it++)
                {
                    if((it->second).first!=i && (it->second).first!=j && (it->second).second!=i && (it->second).second!=j)
                    {
                        found=true;
                        break;
                    }
                }
            }
        }
        
        found?cout<<"1\n":cout<<"0\n";
    }
    return 0;
}

*/