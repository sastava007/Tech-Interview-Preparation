/* 
    Given a BST, in which two nodes are mistakenly swapped. We've find those two nodes and swap them back in O(1) space
    A trivial solution is to do a inorder traversal and store the nodes in a list, and then traverse the left 2 times first from L->R and then from R->L finding the nodes which aren't
    in order and swap their values. But this requires an extra O(N) auxiliarray space.

    We can solve this problem using Morris Traversal which doesnt require any extra space
    
*/


void recoverTree(TreeNode* root) 
{
    TreeNode *pre=NULL, *first=NULL, *second = NULL;
    while(root!=NULL)
    {
        if(root->left == NULL)
        {
            if(pre && pre->val>root->val)
            {
                if(first==NULL)
                {
                    first = pre;
                    second = root;
                }
                else
                    second = root;
            }
            pre = root;
            root = root->right;
        }
        else
        {
            TreeNode *predecessor = root->left;     // connect threading for root
            while(predecessor->right!=NULL && predecessor->right!=root)
                predecessor = predecessor->right;
            
            if(predecessor->right == NULL)  // construct the threading
            {
                predecessor->right = root;
                root = root->left;
            }
            else    // the threading already exists 
            {
                predecessor->right = NULL;
                if(pre && pre->val > root->val)
                {
                    if(first==NULL)
                    {
                        first = pre;
                        second = root;
                    }
                    else
                        second = root;
                }
                pre = root;
                root = root->right;
            }
        }
    }
    if(first && second)     // swap two node values
    swap(first->val, second->val);
}