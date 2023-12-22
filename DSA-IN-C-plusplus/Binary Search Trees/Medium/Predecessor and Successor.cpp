/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    
    void prede(Node* root, Node* &pre, int key){
        while(root!=0){
            if(key <= root->key){
                root = root->left;
            }
            
            else{
                pre = root;
                root = root->right;
            }
        }
    }
    
    void succ(Node* root, Node* &suc, int key){
        while(root != 0){
            if(key >= root->key){
                root = root->right;
            }
            
            else{
                suc = root;
                root= root->left;
            }
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        prede(root , pre, key);
        succ(root, suc, key);
    }
};
