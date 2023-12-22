/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/

class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    
    
    void inorder(Node* root, vector<int>&v){
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
    Node* sortedArrayToBST(vector<int>&nums, int start, int end){
        if(start > end) return NULL;
        
        int mid = start + (end - start)/2;
        Node* root = new Node(nums[mid]);
        
        root->left = sortedArrayToBST(nums, start, mid-1);
        
        root->right = sortedArrayToBST(nums, mid+1, end);
        
        return root;
    }
    
    
    Node* buildBalancedTree(Node* root)
    {
    	// Code here
    	
    	vector<int>v;
    	inorder(root, v);
    	return sortedArrayToBST(v, 0, v.size()-1);
    }
};
