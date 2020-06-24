/*  So idea is to use a DFS, based approach in which we should first process the root node and then recursively call for its children node. And we should enclose each subtree in a set of 
    brackets. 
    And again for constructing back the tree to it's original form, we should create a new node for each recursive call and return it when we encounter a closing brackets. 

    Input = {}
    String = [1[3[5][6]][2][4]]

 */

class Solution {
public:
    string serialize(TreeNode* root) 
    {
        string ans;
        if(root == NULL)
            return ans;

        dfs(root,ans);
        return ans;
    }
    TreeNode * deserialize(string &data)
    {
        if(data.length() == 0)
            return NULL;
            
        int pos = 1;
        return solve(data,pos);
    }

    void dfs(TreeNode* root, string & ans)
    {
        if(root == NULL)
            return ;
        ans += "[";
        ans += to_string(root->label);
        for(int i = 0; i < root->neighbors.size() ; i++) {
                dfs(root->neighbors[i],ans);
        }
        ans += "]";
    }
    TreeNode * solve(string& data,int &pos)
    {
        int num = 0;
        while(isdigit(data[pos]))
        {
            num = num*10 + (data[pos]-'0');
            pos++;
        }
        
        TreeNode * node =  new TreeNode(num);
        while(pos<data.length())
        {
            if(data[pos] == '[' )
                node->neighbors.push_back(solve(data,++pos));
            else if(data[pos] == ']') 
            {
                pos++;
                return node;
            }
        }
    }
};