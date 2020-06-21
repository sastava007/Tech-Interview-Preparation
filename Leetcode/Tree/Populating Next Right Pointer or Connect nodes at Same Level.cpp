/*  Populating next right pointers or Connect the nodes at same level 
    Clarifying Questions to ask?
        1. If tree is a complete binary tree?
        2. Can we use recursive/iterative approach?
        3. Required space complexity?
*/


/* Modifying the level order traversal, by first pushing the right child and then left child. TC: O(N) and Space: O(width of binary tree) */

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
            return NULL;
        
        queue<Node*> q;
        q.push(root);  

        while(!q.empty())
        {
            int size = q.size();
            Node* prev = NULL;
            while(size--)
            {
                Node* curr = q.front();
                q.pop();
                
                curr->next = prev;
                if(curr->right)
                    q.push(curr->right);
                if(curr->left)
                    q.push(curr->left);
                prev = curr;
            }
        }
        return root;
    }
};

/* Iterative solution: Start from first node at each level, and keep on going towards the right using next pointer */

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
            return NULL;
        
        Node* level_start = root;
        while(level_start)
        {
            Node* curr = level_start;       // first node of that level
            while(curr)     // keep going towards right using next pointer
            {
                if(curr->left)
                    curr->left->next = curr->right;
                if(curr->right && curr->next)
                    curr->right->next = curr->next->left;
                
                curr = curr->next;
            }
            level_start = level_start->left;
        }
        return root;
    }
};

/* Recursive solution: Only works for Complete Binary Trees O(N) time & O(N) Space due to recursive call stack */

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
            return NULL;
        util(root);
        return root;
    }
private:
    void util(Node* root)
    {
        if(root==NULL)
            return;

        if(root->left)                                    // connect the left child
            root->left->next = root->right;
        if(root->right && root->next)                   // connect the right child
            root->right->next = root->next->left;
        
        util(root->left);                       // recursively call for the left & right subtree
        util(root->right);
    }
};