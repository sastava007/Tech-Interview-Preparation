/* Convert BST to DLL inplace, given we have access to left and right pointers */

struct node
{
    int val;
    node* left;
    node* right;
}

void convertToDll(node *root, node **head)
{
    if(root==NULL)
        return;
    
    static node *prev = NULL;       //we only want a single copy of prev in our entire recurisve call, and such that everyone can modify it.
    convertToDll(root->left, head);

    if(prev==NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right=root;
    }
    prev=root; //make the current node as previous

    convertToDll(root->right, head);
}

/* Leetcode: Convert BST to circular DLL TC: O(N) ; space O(height) */

class Solution {
public:

    TreeNode * treeToDoublyList(TreeNode * root) 
    {
        if(root==NULL)
            return NULL;
            
        TreeNode* first=NULL;   //here first and last represnts the first and last node in resultant doubly linked list.
        TreeNode* last=NULL;
        
        util(root, &first, &last);
        
        last->right=first;
        first->left=last;
        
        return first;
    }
    
private:
    void util(TreeNode* root, TreeNode** first, TreeNode** last)
    {
        if(root==NULL)
            return;
            
        util(root->left, first, last);
        if(*first==NULL)        // if we are visiting this node for this first time then our first & last will be NULL
        {
            *first=root;
            *last=root;
        }
        else
        {
            (*last)->right=root;
            root->left=*last;
            *last=root;
        }
        util(root->right, first, last);
    }
};