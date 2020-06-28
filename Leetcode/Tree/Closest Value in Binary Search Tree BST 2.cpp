/* 
    Use two stacks to implement predecessor<> and sucessor<>. The predecessor wil basically store the node that are <= target and sucessor will store the lager nodes than target.

    TC: O(logN + K) and Space: O(logN+k)
    It takes O(logN) time to get the predecessor() OR successor() of target value from BST
 */

class Solution {
public:
    vector<int> closestKValues(TreeNode * root, double target, int k) {

        vector<int> result;

        stack<int> predecessor, successor;
        getPredecessor(root, target, predecessor);
        getSuccessor(root, target, successor);

        for(int i=0; i<k; i++)
        {
            if(predecessor.empty()) {
                result.push_back(successor.top());
                successor.pop();
            }
            else if(successor.empty()) {
                result.push_back(predecessor.top());
                predecessor.pop();
            }
            else if(abs(predecessor.top()-target) < abs(successor.top()-target)) {
                result.push_back(predecessor.top());
                predecessor.pop();
            }
            else {
                result.push_back(successor.top());
                successor.pop();
            }
        }
        return result;
    }
private:
    void getPredecessor(TreeNode* root, double target, stack<int> &predecessor) {   //inorder traversal L->R
        if(root==NULL)
            return ;
        
        getPredecessor(root->left, target, predecessor);
        if(root->val > target)
            return;
        predecessor.push(root->val);
        getPredecessor(root->right, target, predecessor);
    }

    void getSuccessor(TreeNode* root, double target, stack<int> &successor) {   //inorder traversal R->L
        if(root==NULL)
            return ;
        
        getSuccessor(root->right, target, successor);
        if(root->val <= target)
            return;
        successor.push(root->val);
        getSuccessor(root->left, target, successor);
    }
};

/*  Here we need to find the K closest nodes to the target value
    
    1. First way is to perform an iterative inorder traversal, and while doing so keep on adding the elements to a list till it's size is less than K, after which check if curresnt node is more closer than that at the front() in the list then update it.
    TC: O(N) and Space: O(N) 
 */

class Solution {
public:
    vector<int> closestKValues(TreeNode * root, double target, int k) 
    {
        vector<int> result;
        queue<int> temp;
      
        stack<TreeNode*> todo;
        TreeNode* curr = root;    
        while(!todo.empty() || curr)
        {
            if(curr)
            {
                todo.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = todo.top();
                todo.pop();
                if(temp.size()<k)
                    temp.push(curr->val);
                else if(abs(temp.front()-target) > abs(curr->val-target))
                {
                    temp.pop();
                    temp.push(curr->val);
                }
                curr = curr->right;
            }
        }
        while(!temp.empty())
        {
            result.push_back(temp.front());
            temp.pop();
        }
        return result;
    }
};

