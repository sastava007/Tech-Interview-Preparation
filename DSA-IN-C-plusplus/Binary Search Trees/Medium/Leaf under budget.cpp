/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    int getCount(Node *root, int k)
    {
        //code here
        queue<pair<Node*, int>> q;
        q.push({root, 1});
        int count = 0;
        
        while(!q.empty() && k>0){
            auto node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(!node->left && !node->right){
                if(level > k){
                    return count;
                }
                
                ++count;
                k-=level;
            }
            
            else{
                if(node->left) q.push({node->left, level+1});
                if(node->right) q.push({node->right, level+1});
            }
        }
        
        return count;
    }
};
