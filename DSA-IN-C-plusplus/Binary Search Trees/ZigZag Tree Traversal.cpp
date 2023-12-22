//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	int level = 1; 
    	vector<int> ans;
    	queue<Node*> q;
    	q.push(root);
    	
    	while(!q.empty()){
    	    vector<int>temp;
    	    
    	    int n = q.size();
    	    
    	    while(n--){
    	        temp.push_back(q.front()->data);
    	        if(q.front()->left) q.push(q.front()->left);
    	        if(q.front()->right) q.push(q.front()->right);
    	        q.pop();
    	    }
    	    
    	    if(level % 2 == 0){
    	        reverse(temp.begin(), temp.end());
    	    }
    	    
    	    for(int i=0; i<temp.size(); i++){
    	        ans.push_back(temp[i]);
    	    }
    	    
    	    level++;
    	}
    	
    	
    	return ans;
    }
};
