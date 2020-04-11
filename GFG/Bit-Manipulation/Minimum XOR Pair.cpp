/*
    https://www.quora.com/Computer-Programming-How-do-I-find-a-pair-of-numbers-in-an-array-such-that-their-XOR-is-the-minimum
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

int main()
{
    IOS;

    int t;
    cin>>t;
    while (t--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int max_xor=INT_MAX;
        for(i=0;i<n-1;i++)
        max_xor=min(max_xor, a[i]^a[i+1]);

        cout<<max_xor<<"\n";
    }

    return 0;
}