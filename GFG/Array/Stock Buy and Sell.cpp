/*
    We sell the stock when prices are highest and buy when prices are lowest, and in order to find highest and lowest price
    I have used localMaxima & localMinima and I keep on updating them while iterating
    This problem assumes that you can not buy & sell stocks on the same day.
    Consider this TC for better understanding: 
    (100, 180, 260, 310), 120, (40, 595)
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,lmin,lmax;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        lmin=0,lmax=0;
        vector<pair<int,int>> ans;
        for(i=1;i<n;i++)
        {
            if(a[i]<a[lmax])
            {
                if(lmax-lmin >=1)
                    ans.push_back({lmin,lmax});
                lmax=i;
                lmin=i;
            }
            lmax = a[i]>=lmax?i:lmax;
        }
        if(lmax==n-1 && lmax-lmin>=1)
        ans.push_back({lmin,lmax});
        if(ans.size()!=0)
            for(auto it:ans)
            {
                cout<<"("<<it.first<<" "<<it.second<<") ";
            }
        else
        cout<<"No Profit";
        
        cout<<"\n";
    }
	return 0;
}

