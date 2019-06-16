/*
        Find the expectation that each value in subarray formed between range l-r has unique set of elements
        Use Linear DP || Mathematical Expectation
        Codeforces: https://codeforces.com/problemset/problem/846/F
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll last_occur[1000006]={0};
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,i;
    cin>>n;
    ll a[n+1];
    for(i=1;i<=n;i++)
        cin>>a[i];

    // to store the last ocurrence of element and update the ans as ans[i]=ans[i-1]+(curr_index-last_occuence of a[i])
    // Here I have used linear DP

    ll ans[n+1];
    ans[0]=0;
    double sum=0.0;
    for(i=1;i<=n;i++)
    {
        ans[i]=ans[i-1]+(i-last_occur[a[i]]);
        last_occur[a[i]]=i;
        sum+=ans[i];
    }
    double final_ans=(2*(sum-n)+n)/(n*n);
    cout<<fixed<<setprecision(6)<<final_ans<<"\n";
}
