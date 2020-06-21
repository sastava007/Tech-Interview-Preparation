/*  Idea is to do a pre-order traversal to convert the BST into linear string. And unlike typical serialize & deserialize BT, here we don't need to add "#" for NULL node,
    and we should use property of BST to generate the tree back.

    The string obtained after serializing() should be as compressed as possible.

 */

class Codec {
    
public:
    string serialize(TreeNode* root) 
    {
        string res = "";
        serialize(root, res);
        return res;
    }
    
    TreeNode* deserialize(string data) 
    {
        if (data.length()==0) 
            return NULL;
        int index = 0;    
        
        return deserialize(data, index, INT_MIN, INT_MAX);
    }
private:
    void serialize(TreeNode* root, string& s) 
    {
        if (root == NULL)
            return;
            
        s += to_string(root->val) + ",";
        serialize(root->left, s);
        serialize(root->right, s);
    }
    
     TreeNode* deserialize(string s, int &index, int lower_limit, int upper_limit) 
     {
         if(index >= s.length())
             return NULL;
         
         int j=index;
         while(s[j] != ',')
         {
             j++;
         }
         
         int val = stoi(s.substr(index, j-index));
         
         if(val<=lower_limit || val>=upper_limit)
             return NULL;
         
         index = j+1;
         
         TreeNode* node = new TreeNode(val);
         node->left = deserialize(s, index, lower_limit, val);
         node->right = deserialize(s, index, val, upper_limit);
         
         return node;
    }
};