/*
    Maximum XOR Subarray, this problem is reduced to maximum XOR pair 
    https://www.hackerrank.com/challenges/xor-key/topics
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

struct trienode
{
    trienode *left;
    trienode *right;
};

void insert(int n, trienode *head)
{
    trienode *curr = head;

    for(int i=31;i>=0;i--)
    {
        int bit = n&(1<<i);
        if(bit==0)
        {
            if(!curr->left)
                curr->left=new trienode();
            curr=curr->left;
        }
        else
        {
            if(!curr->right)
                curr->right=new trienode();
            curr=curr->right;
        }
    }
}

int maxXORQuery(int a, trienode *head)
{
    trienode *curr = head;
    int cur_xor =0;
    for (int j = 31; j >=0 ; j--)
    {
        int bit = a&(1<<j);
        if(bit==0)
        {
            if(curr->right)
            {
                curr=curr->right;
                cur_xor+=(1<<j);
            }
            else
            {
                curr=curr->left;
            }
        }
        else
        {
            if(curr->left)
            {
                curr=curr->left;
                cur_xor+=(1<<j);
            }
            else
            {
                curr=curr->right;
            }
        }
    }
    return cur_xor;
}

int main()
{
    IOS;

    int t;
    cin>>t;
    while (t--)
    {
        int n,i;
        cin>>n;
        int pre_xor = 0, ans=0;
        int a[n];
        trienode *head=new trienode();
        
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            pre_xor^=a[i];
            insert(pre_xor,head);
            ans = max(ans, maxXORQuery(pre_xor, head));
        }

        cout<<ans<<"\n";
    }

    return 0;
}