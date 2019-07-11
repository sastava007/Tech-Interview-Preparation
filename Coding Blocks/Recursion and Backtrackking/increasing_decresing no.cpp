#include<bits/stdc++.h>
using namespace std;
#define ll long long

int increasing(int n)
{
    if(n==1)
    {
        cout<<"1\n";
        return 1;
    }
    int ans=1+increasing(n-1);
    {
        cout<<ans<<"\n";
        return ans;
    }

}

int decreasing(int n)
{
    if(n==1)
    {
        cout<<"1\n";
        return 1;
    }
    cout<<n--<<"\n";
    decreasing(n);

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n=5;
    increasing(5);
    decreasing(5);
}

