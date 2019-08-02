/*August Long Challenge Div2: https://www.codechef.com/AUG19B/problems/MSNSADM1*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<<"\n";


main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],b[n];
        int max_score=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        cin>>b[i];

        for(i=0;i<n;i++)
        {
            int temp=20*a[i]-10*b[i];
            if(temp<0)
            temp=0;
            max_score=max(max_score,temp);
        }
        cout<<max_score<<"\n";
    }
}
