class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
      if(root == nullptr) return 0;
      dfs(root, 0, 1); //position of this node and the current depth
      return maxWidth;
    }
  
private:
  int maxWidth = INT_MIN;
  unordered_map<int, unsigned long int> leftPosition; //[depth] : [leftmostnode Position]
  void dfs(TreeNode* root, unsigned long int position, int depth)
  {
    if(root == nullptr) return;
    
    //Only if a leftModeNode position is not already present at this depth
    if(leftPosition.count(depth) == 0){
      leftPosition[depth] = position;
    } 
    
    int leftMostposition = leftPosition[depth];
    /*Calculate the max width*/
    int widthAtCurrentDepth = position - leftMostposition + 1;
    maxWidth = max(maxWidth, widthAtCurrentDepth);
    
    dfs(root->left, position*2, depth+1);
    dfs(root->right, position*2 + 1, depth+1);
  }
};