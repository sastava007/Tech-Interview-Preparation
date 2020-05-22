void serialize(Node *root,vector<int> &A)
{
    if(root==NULL)
    {
        A.emplace_back(-1);
        return;
    }
    A.emplace_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
}

Node * deSerialize(vector<int> &A, int &pointer)
{
    if(A.size()==0 || A[pointer]==-1)
    {
        pointer++;
        return NULL;
    }
    
    Node* temp = new Node(A[pointer]);
    pointer++;
        
    temp->left=deSerialize(A, pointer);
    temp->right=deSerialize(A, pointer);
    
    return temp;
}
Node * deSerialize(vector<int> &A)
{
    int pointer = 0;
    return deSerialize(A, pointer);
}

/* Using string instead of vector<> */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mydeserialize(data);
    }
    TreeNode* mydeserialize(string& data) {
        if (data[0]=='#') {
            if(data.size() > 1) data = data.substr(2);
            return nullptr;
        } else {
            TreeNode* node = new TreeNode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }
private:
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};`