/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    int ans;
    void dfs(Node* root, int& k){
        if(root == NULL) return;
        dfs(root->right, k);
        k--;
        if(k==0){
            ans = root->data;
            return;
        }
        
        dfs(root->left, k);
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        dfs(root, k);
        return ans;
    }
};
