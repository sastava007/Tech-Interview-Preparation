#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

struct matrixArray
{
    vector<int> v[2];
};
matrixArray I,seg[400005],matrix[100001];

int mod;

matrixArray matrixMultiply(matrixArray a,matrixArray b)
{
    int i,j,x;
    matrixArray ans;
    for(i=0;i<2;i++)
    for(j=0;j<2;j++)
    {
        ll sum=0;
        for(x=0;x<2;x++)
        {
            sum+=(a.v[i][x]*b.v[x][j]);
        }
        ans.v[i].emplace_back(sum%mod);
    }

    return ans;
}

void builtseg(int low, int high, int node)
{
    if(low==high)
    {
        seg[node]=matrix[low];
        return;
    }
    int mid=(low+high)/2;
    builtseg(low,mid,2*node+1);
    builtseg(mid+1,high,2*node+2);
    seg[node]=matrixMultiply(seg[2*node+1],seg[2*node+2]);
    return;
}

matrixArray query(int qlow, int qhigh, int low, int high, int node)
{
    if(high<qlow || low>qhigh)          /// no overlapping
        {
            return I;
        }
    if(low>=qlow && high<=qhigh)        ///total overlapping
    {
        return seg[node];
    }
    int mid=(low+high)/2;
    return matrixMultiply(query(qlow,qhigh,low,mid,2*node+1),query(qlow,qhigh,mid+1,high,2*node+2));
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    I.v[0].emplace_back(1); I.v[0].emplace_back(0);
    I.v[1].emplace_back(0); I.v[1].emplace_back(1);

    int n,q,i,j,k;
    cin>>mod>>n>>q;

    int temp;
    for(i=0;i<n;i++)
    {
        int temp;
        for(j=0;j<2;j++)
            for(k=0;k<2;k++)
            {
                cin>>temp;
                matrix[i].v[j].emplace_back(temp);
            }
    }


    builtseg(0,n-1,0);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        matrixArray ans=query(l-1,r-1,0,n-1,0);
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
                cout<<ans.v[i][j]<<" ";
                cout<<"\n";
        }
        cout<<"\n";
    }
}
