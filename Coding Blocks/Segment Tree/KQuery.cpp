

    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define deb(x) cout<<#x<<" "<<x<"\n"

    vector<ll> seg[400005];     ///2D vector: to store elements at each node level
    vector<ll> a(100000);

    void builtTree(int low, int high, int node)
    {
        if(low==high)
        {
            seg[node].emplace_back(a[low]);
            return;
        }
        int mid=(low+high)/2;
        builtTree(low,mid,2*node+1);
        builtTree(mid+1,high,2*node+2);
        merge(seg[2*node+1].begin(),seg[2*node+1].end(),seg[2*node+2].begin(),seg[2*node+2].end(),back_inserter(seg[node]));
    }

    ll query(int qlow, int qhigh, int low, int high, ll node, ll k)
    {
        if(qlow>high || low>qhigh)      /// no overlapping
            return 0;

        if(low>=qlow && high<=qhigh)
        {
            return seg[node].size()-(upper_bound(seg[node].begin(),seg[node].end(),k)-seg[node].begin());
        }

        int mid=(low+high)/2;
        ll left=query(qlow, qhigh, low, mid, 2*node+1, k);
        ll right=query(qlow, qhigh, mid+1, high, 2*node+2, k);
        return left+right;
    }

    main()
    {
        fast;
        int n,q,i;
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];

        builtTree(0,n-1,0);
        cin>>q;
        int l,r;
        ll k;
        while(q--)
        {
            cin>>l>>r>>k;
            if(l>r || l>n || r>n)
                cout<<"0\n";
            else if(l==r)
            {
                a[l-1]>k?cout<<"1\n":cout<<"0\n";
            }
            else
            cout<<query(l-1,r-1,0,n-1,0,k)<<"\n";
        }

    }




























