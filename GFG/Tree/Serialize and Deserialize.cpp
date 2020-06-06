/*  LC Version:  Using string led to constant storage space
    Preorder traversal to serialize the binary tree.

*/

class Codec {
public:
    string serialize(TreeNode* root) 
    {
        if(root==NULL)
            return "#";
        string s = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        return s;
    }
    TreeNode* deserialize(string data) 
    {
        stringstream s(data);
        return deserialize(s);
    }
private:
    TreeNode* deserialize(stringstream &s)
    {
        string token;
        getline(s, token, ',');
 
        if(token=="#")
            return NULL;
        
        TreeNode* temp = new TreeNode(stoi(token));
        temp->left = deserialize(s);
        temp->right = deserialize(s);
        
        return temp;
    }
};

/* Iterative Traversal */

class Codec {
public:

    // Iterative preorder encode

    string serialize(TreeNode* root) {
        stack<TreeNode*> s;
        string output;

        s.push(root);
        while(s.size()) {
            TreeNode *node = s.top();
            s.pop();
            if (output.size()) output += ",";
            output += node ? to_string(node->val) : "#";
            if (node) {
                s.push(node->right);
                s.push(node->left);
            }
        }
        return output;
    }

    // Iterative preorder decode

    TreeNode* deserialize(string data) {
        stringstream datastream(data);
        TreeNode *root = NULL;
        stack<TreeNode**> s;
        string token;
        
        s.push(&root);
        while (s.size()) {
            TreeNode **node = s.top();
            s.pop();
            getline(datastream, token,',');
            *node = token == "#" ? NULL : new TreeNode(stoi(token));
            if (*node) {
                s.push(&((*node)->right));
                s.push(&((*node)->left));
            }
        }
        return root;
    }
};

/* Using vector: O(N) space for storage */

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