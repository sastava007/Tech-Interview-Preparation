#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {   
        int i,n;
        cin>>n;
        int a[n], prev=-1;
        bool followed=true;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)
            {
                if((prev!=-1) && (i-prev)<6)
                {
                    followed=false;
                }
                prev=i;
            }
        }
        followed?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}