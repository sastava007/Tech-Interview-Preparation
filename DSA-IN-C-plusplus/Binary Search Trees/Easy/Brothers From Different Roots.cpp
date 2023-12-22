//User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    
    map<int, bool> mp;
    
    void insert_nodes(Node* root){
        if(root == NULL) return;
        
        mp[root->data] = true;
        if(root->left) insert_nodes(root->left);
        if(root->right) insert_nodes(root->right);
    }

    int count = 0;
    void count_helper(Node* root, int x){
        if(root==NULL) return;
        if(mp[x-root->data]) count++;
        if(root->left) count_helper(root->left, x);
        if(root->right) count_helper(root->right, x);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        insert_nodes(root1);
        count_helper(root2, x);
        return count;

    }
};
