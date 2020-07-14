/*  Convert BST to a sorted DLL inplace

    So here, basically we've to treat TreeNode's left & right pointers as previous & next pointer of DLL. 

    Idea is to perform an inorder traversal and keep track of the previous processed node, then for every encountered node we set it's left child to prev and prev right child
    to current node. 
*/

void convert(Node* root)
{
	Node *prev = nullptr;   // to keep track of previous processed node in inorder traversal
    
	convert(root, root, prev);  // the root node of tree is now the head of DLL
}

void convert(Node* curr, Node*& head, Node* &prev)
{
	if (curr == nullptr)
		return;

	convert(curr->left, head, prev);

	if (prev != nullptr)
	{
		curr->left = prev;      // set current node's left child to prev
		prev->right = curr;     // make prev's right child point to curr
    }
	else                        
		head = curr;        // if prev is null, then set head of DLL as this is first node in inorder

	prev = curr;                        // after current node is visited, update previous pointer to current node
	convert(curr->right, head, prev);
}



/* Leetcode: Convert BST to circular DLL TC: O(N) ; Space O(height) */

class Solution {
public:

    TreeNode * treeToDoublyList(TreeNode * root) 
    {
        if(root==NULL)
            return NULL;
            
        TreeNode* first=NULL;   //here first and last represnts the first and last node in resultant doubly linked list.
        TreeNode* last=NULL;
        
        util(root, first, last);
        
        last->right=first;
        first->left=last;
        
        return first;
    }
    
private:
    void util(TreeNode* root, TreeNode* &first, TreeNode* &last)
    {
        if(root==NULL)
            return;
            
        util(root->left, first, last);
        if(*first==NULL)        // if we are visiting this node for this first time then our first & last will be NULL
        {
            first=root;
            last=root;
        }
        else
        {
            (last)->right=root;
            root->left=last;
            last=root;
        }
        util(root->right, first, last);
    }
};