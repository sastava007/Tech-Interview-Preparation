/*  Given N elements (1,2,........i.........N) we have to find number of BSTs possible which can be built over them.
 *  Let f(i) represents number of BST formed fixing "i" as node then f(i-1) denotes no of BSTs in left subtree and f(n-i) denotes no of possible BSTs in right subtree.
 *  To make a tree you need to choose one left and one from right. so product and do sum
 *  f(i)-f(i-1)*f(n-i) and we can choose any element as node from 1 to N so do their summation
 *  https://www.geeksforgeeks.org/total-number-of-possible-binary-search-trees-using-catalan-number/
 */


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

ll countBST(int n)
{
    if(n==0 || n==1)        ///when n=0, means there will be 1 null BST
        return 1;

    ll ans=0;
    for(int i=1;i<=n;i++)
        {
            ll n1=countBST(i-1);
            ll n2=countBST(n-i);
            ans+=(n1*n2);
        }

    return ans;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cout<<countBST(n);

}
