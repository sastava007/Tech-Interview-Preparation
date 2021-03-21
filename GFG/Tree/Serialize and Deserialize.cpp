/*  
    
    LC Version:
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

/* Iterative Preorder Traversal */

class Codec {
public:

    string serialize(TreeNode* root) 
    {
        stack<TreeNode*> s;
        string output;

        s.push(root);
        while(s.size())
        {
            TreeNode *node = s.top();
            s.pop();
            if (output.size())
                output += ",";
            output += node ? to_string(node->val) : "#";    // if null node, then add "#" else add node->val
            if (node) 
            {
                s.push(node->right);
                s.push(node->left);
            }
        }
        return output;
    }

    // Iterative preorder decode

    TreeNode* deserialize(string data)
    {
        stringstream datastream(data);
        TreeNode *root = NULL;
        stack<TreeNode**> s;
        string token;
        
        s.push(&root);
        while (s.size())
        {
            TreeNode **node = s.top();
            s.pop();
            getline(datastream, token,',');
            *node = token == "#" ? NULL : new TreeNode(stoi(token));
            if (*node) 
            {
                s.push(&((*node)->right));
                s.push(&((*node)->left));
            }
        }
        return root;
    }
};

/* LevelOrder traversal using Queue */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> q;
        string s;
        if (root) q.push(root);
        while (!q.empty()) {
            TreeNode *n = q.front();
            q.pop();
            if (n) {
                q.push(n->left);
                q.push(n->right);
                s += to_string(n->val) + ",";
            } else {
                s += "n,";
            }
        }
        if (s.length()) s.erase(s.find_last_not_of("n,")+1);
        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        queue<string> qData;
        int i = 0, j;
        do {
            j = data.find(',', i);
            if (j != string::npos) qData.push(data.substr(i, j-i));
            else qData.push(data.substr(i));
            i = j+1;
        } while (j != string::npos);
        
        queue<TreeNode *> qNodes;
        TreeNode *root = new TreeNode(stoi(qData.front()));
        TreeNode *curr = NULL;
        qNodes.push(root);
        qData.pop();
        while (!qData.empty()) {
            string val1 = "", val2 = "";
            val1 = qData.front();
            qData.pop();
            if (!qData.empty()) {
                val2 = qData.front();
                qData.pop();
            }
            curr = qNodes.front();
            qNodes.pop();
            if (val1 != "" && val1 != "n") {
                curr->left = new TreeNode(stoi(val1));
                qNodes.push(curr->left);
            }
            if (val2 != "" && val2 != "n") {
                curr->right = new TreeNode(stoi(val2));
                qNodes.push(curr->right);
            }
        }
        return root;
    }
};


/* Preorder: Using vector: O(N) space for storage */

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