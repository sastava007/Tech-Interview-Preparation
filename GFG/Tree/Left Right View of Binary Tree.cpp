/* Right Side view using Recursion: O(N) TC & O(h) space due to call stack but it can be in order of N incase of a skewed binary Tree */

// DFS Approach
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        int maxLevel = -1;
        util(root, 0, maxLevel, ans);
        return ans;
    }
private:
    void util(TreeNode* root, int level, int &maxLevel, vector<int> &ans)
    {
        if(root==NULL)
            return;
        
        if(level>maxLevel)
            ans.emplace_back(root->val);    // doing a preorder traversal
        
        maxLevel = max(maxLevel, level);
        
        util(root->right, level+1, maxLevel, ans);
        util(root->left, level+1, maxLevel, ans);
    }
};

/* Right View without using Recursion */

// BFS Approach
void rightView(Node* node)
{
    if(node==NULL)
    return;
    
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        int size = q.size();
        while(size--)
        {
            Node* temp = q.front();
            q.pop();
            
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }
    }
}

/* Left view Using Recursion */
void leftViewUtil(Node *root, int level, int &maxLevel)
{
    if(root==NULL)
        return ;
    
    if(level>maxLevel)
    {
        cout<<root->data<<" ";
        maxLevel=level;
    }
    
    leftViewUtil(root->left, level+1, maxLevel);
    leftViewUtil(root->right, level+1, maxLevel);
}
void leftView(Node *root)
{
    int maxLevel=-1;
    leftViewUtil(root, 0, maxLevel);
}

/* Left view Without Recursion */
void leftView(Node* node)
{
    if(node==NULL)
    return;
    
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        int size = q.size();
        while(size--)
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}