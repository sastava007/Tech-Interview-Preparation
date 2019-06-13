#include<bits/stdc++.h>
using namespace std;

bool check_sum(int *a,int n,int sum)
{
    int total=0,i=0;
    bool found=false;
    while(n>0)
    {

        if(n&1==1)
        total+=a[i];
        if(total==sum)
        {
            found=true;
            break;
        }
        i++;
        n=n>>1;

    }
    return found;
}

// There are total 2^n-1 subsets because each element can either chosen or not so each element has 2 possibilities Subsets can be formed in O(2^n) time
// After generating all subsets check that whether sum of all elements in that subset is equal to K or not and this can be checked in O(n) time
// So total time complexicity of this code is O(n*2^n)

void generate_subsets(int *a,int n,int m)
{
    int range=(1<<n)-1;
    string found="No";
    for(int i=0;i<=range;i++)
    if(check_sum(a,i,m))
    {
        found="Yes";
        break;
    }
    cout<<found<<"\n";
    return;

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    int n,m;
    while(t--)
    {
        cin>>n>>m;
        int a[n];
        for(i=0;i<n;i++)
        cin>>a[i];
        generate_subsets(a,n,m);

    }
}
