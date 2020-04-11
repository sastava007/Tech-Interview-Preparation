/*
    Maximum XOR pair using BIT in O(nlogm)
    For every number in the array, convert it into binary, and insert it into a bit tree.  (every time you get bit 1, go right, bit 0 go left)
    Now, again loop through the entire array and for each number compute the "best" number that will give you the max xor. so if a[1] is 01001100, 
    its best compliment is 10110011.  Now try to find this number in the bit tree.
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

int maxXORPair(int *a, int n, trienode *head)
{
    int max_xor = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        trienode *curr = head;
        int cur_xor =0;
        for (int j = 31; j >=0 ; j--)
        {
            int bit = a[i]&(1<<j);
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
            max_xor=max(max_xor,cur_xor);
        }
    }
    return max_xor;
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
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        // build the BIT tree for all a[i] elements
        trienode *head=new trienode();
        for(i=0;i<n;i++)
            insert(a[i],head);

        cout<<maxXORPair(a,n,head)<<"\n";
    }

    return 0;
}