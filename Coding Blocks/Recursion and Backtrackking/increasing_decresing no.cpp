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

int mul(int a,int b)
{
    if(b==1)
        return a;
    int ans=a+mul(a,b-1);
    return ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n=5;
    //increasing(5);
    //decreasing(5);
    int a,b;
    cin>>a>>b;
    bool res=(a*b)<0;
    if(b<0)
        b*=-1;
    if(a<0)
        a*=-1;
    if(!res)
    cout<<mul(a,b);
    else
        cout<<-1*mul(a,b);
}

