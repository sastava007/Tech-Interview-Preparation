/*  
    Idea is to do a (BFS) level order tarversal, and consider the fact that if root node is present at position 'i' then it's left & right child will be present at '2i+1' and '2i+2' respectively. 
    This way we can, keep on checking the leftmost and rightmost position at each level and difference of both extreme positions will be our maximum width.

    TC: O(N)
    Space: O(N) Worst case when tree is balanced, becz balanced tree has 2^h nodes at last level where h is height = log(n) => 2^(log2N) = N
                Best Case: When tree is degenerated linked list(skewed), O(1)


                   1
                  / \
                 3   2
                /     \  
               5       9 
              /         \
             6           7

             max-width = 8
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        if(root == nullptr) 
            return 0;
      
        unsigned long int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            int size = q.size();
            unsigned long int leftmost = q.front().second, rightmost = q.front().second;
            while(size--)
            {
                auto node = q.front();
                q.pop();
                
                leftmost = min(leftmost, node.second);    // find the extreme leftmost position
                rightmost = max(rightmost, node.second);  // find the extreme rightmost position
        
                if(node.first->left)
                    q.push({node.first->left, 2*node.second+1});
                if(node.first->right)
                    q.push({node.first->right, 2*node.second+2});
            }
            maxWidth = max(maxWidth, rightmost-leftmost+1);
        }
      return maxWidth;
    }
};


/* DFS approach, maintaining the leftmost position at each level/depth using an extra unordered_map */

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