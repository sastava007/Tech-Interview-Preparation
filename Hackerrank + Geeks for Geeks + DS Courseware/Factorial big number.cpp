#include<bits/stdc++.h>
#define MAX 500
using namespace std;

void factorial(int n)
{
    int res[MAX],carry=0,l=1;
    res[0]=1;

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<l;j++)
        {
            int temp=carry+i*res[j];
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
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    factorial(n);
}
