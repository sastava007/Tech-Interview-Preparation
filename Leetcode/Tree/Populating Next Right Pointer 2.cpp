/*  This solution is for general cases, tree need not to be complete binary tree 
    
    Idea: Maintain 3 pointers [parent, child, and childHead] and run two loops. The outer one will be responsible for traversing vertically and inner loop for tarversing across levels.
    
    childHead - will point to the 1st node of each level
    child - will actually move across the levels

    TC: O(N) and Space: O(1)
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        Node *parent = root, *child = NULL, *childHead = NULL;
        
        while(parent)
        {
            while(parent)
            {
                if(parent->left)
                {
                    if(childHead==NULL)
                        childHead = parent->left;
                    else
                        child->next = parent->left;
                    child = parent->left;               // move to the next node in/across level
                }
                if(parent->right)
                {
                    if(childHead==NULL)
                        childHead = parent->right;
                    else
                        child->next = parent->right;
                    child=parent->right;
                }
                parent = parent->next;      // move across level
            }
            parent = childHead;
            childHead = child = NULL;
        }
        
        return root;
    }
};