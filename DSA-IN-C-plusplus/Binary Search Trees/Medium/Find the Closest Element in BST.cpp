/*
Tree Node
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

class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        //Your code here
        Node* curr = root;
        int ans = INT_MAX;
        while(curr != NULL){
            ans = min(ans, abs(K-curr->data));
            
            if(K<=curr->data) curr = curr->left;
            
            else curr = curr->right;
        }
        
        return ans;
    }
};
