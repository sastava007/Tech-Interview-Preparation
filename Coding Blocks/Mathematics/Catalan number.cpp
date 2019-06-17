#include<bits/stdc++.h>
#define MAX 500
using namespace std;

int catalan(int n)
{
    cpp_int ans=1;
    for(int i=2;i<=n;i++)
        ans=(ans*(n+i))/i;
    return ans;
}

/*
void catalan(int n)
{
    long long int res[MAX],carry=0,l=1;
    res[0]=1;

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<l;j++)
        {
            long long int temp=carry+((n+i)*res[j])/i;
            res[j]=temp%10;
            carry=temp/10;
        }

        while(carry>0)
        {
                res[l++]=carry%10;
                carry/=10;
        }
    }
    for(int i=l-1;i>=0;i--)
        cout<<res[i];
}*/

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    catalan(n);
}
