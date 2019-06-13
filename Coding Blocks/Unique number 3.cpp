#include<bits/stdc++.h>
using namespace std;

static int cnt[64]={0};

void extract_bits(int n)
{
    int i=0;
    while(n>0)
    {
        if(n&1==1)
        cnt[i]++;
        n=n>>1;
        i++;
    }
    return;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        extract_bits(a[i]);
    }
    int ans=0;
    for(i=0;i<64;i++)
    {
        cnt[i]%=3;
        ans+=cnt[i]*pow(2,i);
    }
    cout<<ans;

}
