
class Solution{
    private:
        unordered_map<int, int>mp;
        void traverse(Node* root){
            if(!root) return;
            
            mp[root->data]++;
            
            traverse(root->left);
            traverse(root->right);
        }
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2){
     //Your code here
     
     vector<int>result;
     
     traverse(root1);
     traverse(root2);
     
     
     for(auto &kp : mp){
         if(kp.second == 2){
             result.push_back(kp.first);
         }
     }
     
     sort(result.begin(), result.end());
     
     return result;
     
     
     
    }
};

