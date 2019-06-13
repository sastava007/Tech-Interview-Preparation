#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    int n,i;

    while(t--)
    {
        scanf("%d",&n);
        vector<int> v(n);
        int a[n];

        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            v[i]=a[i];

        }
        sort(v.begin(),v.end());
        for(i=0;i<n;i++)
        {
            auto it=lower_bound(v.begin(),v.end(),a[i]);
            printf("%d ",it-v.begin());
            v.erase(it);
        }
        printf("\n");
    }

}
