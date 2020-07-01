/*  LC version: Here we've to return the edges and not nodes, so don't include the root node while checking for maximum 
    TC & Space: O(N)
*/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter = 0;
        int dump = util(root, diameter);
        
        return diameter;
    }
private: 
    int util(TreeNode* root, int &diameter)
    {
        if(root==NULL)
            return 0;
        
        int longestPathInLeftSubtree = util(root->left, diameter);
        int longestPathInLeftSubtree = util(root->right, diameter);
        
        diameter = max(diameter, longestPathInLeftSubtree + longestPathInLeftSubtree);
        
        return max(longestPathInLeftSubtree, longestPathInLeftSubtree) + 1;
    }
};

/* To Print Path as Well */

int height(Node* root, int& ans, Node*(&k), int& lh, int& rh) 
{ 
	if (root == NULL) 
		return 0; 

	int left_height = height(root->left, ans, k, lh, rh, f); 
	int right_height = height(root->right, ans, k, lh, rh, f); 

	if (1 + left_height + right_height > ans)
    {
		ans = 1 + left_height + right_height;
		k = root;
		lh = left_height;
		rh = right_height;
	} 

	return 1 + max(left_height, right_height); 
} 

void printPathsRecur(Node* node, vector<int> path, vector<int> &completePath ,int pathLen, int max, int &flag) 
{ 
	if (node == NULL)
		return;
	path.push_back(root->data);
    pathLen++;

	if (node->left == NULL && node->right == NULL)  // If it's a leaf, so print the path that led to here 
    {
		if (pathLen == max && (flag == 0 || flag == 1))   // Once we reach the leaf node with this path length, and f=0 means leftsubtree f=1 means right
        {
            if(flag==0)
                reverse(path.begin(), path.end());
            completePath.insert(completePath.end(), path.begin(), path.end());
			flag = 2;
            return;
		}
	}
	else 
    {
		printPathsRecur(node->left, path, pathLen, max, flag); 
		printPathsRecur(node->right, path, pathLen, max, flag); 
	}
}
vector<int> diameter(Node* root) 
{ 
	if (root == NULL) 
		return; 

	int ans = INT_MIN, lh = 0, rh = 0, flag = 0, pathLen = 0; 

	Node* k;    // to store the root node of diameter
	int height_of_tree = height(root, ans, k, lh, rh); 

    vector<int> lPath, rPath, completePath;

	printPathsRecur(k->left, lPath, completePath, pathlen, lh, flag);       // add left path of diameter
    completePath.push_back(k->data);    // add root node of diamtere
	flag = 1; 
	printPathsRecur(k->right, rPath, completePath, pathlen, rh, flag);     // add right path of diameter

    return completePath;
} 


/* First check definition for Diameter of binary Tree: i.e if they are asking for no. of nodes on maximum path or edge of maximum path*/

int ans;
int diameterUtil(Node* node) 
{
    if(node==NULL)
        return 0;
    
    int longestPathInLeftSubtree = diameterUtil(node->left);
    int longestPathInLeftSubtree = diameterUtil(node->right);
    
    ans=max(ans, longestPathInLeftSubtree + longestPathInRightSubtree + 1); //here we are returning no. of nodes on longest path b/w two leaves of binary tree
    
    return max(longestPathInLeftSubtree,longestPathInRightSubtree)+1;   //this will give longest in subtree rooted under current node.

int diameter(Node* node)
{
   ans=0;
   int temp = diameterUtil(node);
   return ans;
}


/* Using iterative postorder traversal */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if (!root) 
        {
            return 0;
        }
        
        int diameter = 0;
        unordered_map<TreeNode*, int> depths;
        stack<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty())
        {
            TreeNode* node = todo.top();
            if (node -> left && depths.find(node -> left) == depths.end()) {
                todo.push(node -> left);
            } else if (node -> right && depths.find(node -> right) == depths.end()) {
                todo.push(node -> right);
            } else {
                todo.pop();
                int l = depths[node -> left], r = depths[node -> right];
                depths[node] = max(l, r) + 1;
                diameter = max(diameter, l + r);
            }
        }
        return diameter;
    }
};