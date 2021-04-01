/* 
    Given a contaminated tree with all values as "-1", we've recover the tree such that root->val = 0, root->left->val = 2x+1 and root->right->val = 2x+2 
    After that we've to find whether a given value is present or not.

    1. Typical Solution: TC: O(1) & Space: O(N) 
        is to use hashset and store all the values as we encounter while recovering the tree, but this would not scale if there are large no. of elements.

    2. Smart Solution: TC: O(logN) & Space: O(1)

        A complete tree will have numbers in each layer range from [2^i-1,2^(i+1)-2]
        what if we add 1 to each number? Then it should range from [2^i, 2^(i+1)-1]
        See? the binary of all numbers in each layer should be: 100..00  to  111...11

        So what we can do is that to add +1 to target and search for (target+1) in our Tree

                   1
            10          11
       100     101 110      111

       Going left appends '0', and going right appends '1'
*/

class FindElements {
private:
  TreeNode *root;

public:
  FindElements(TreeNode *root) {
    this->root = root;
    recover(root, 0);
  }
  void recover(TreeNode *root, int x) {
    if (!root)
      return;
    root->val = x;
    if (root->left)
      recover(root->left, 2 * x + 1);
    if (root->right)
      recover(root->right, 2 * x + 2);
  }

  bool find(int target) {
    TreeNode *curr = root;
    target++;
    int temp = target, len = 0;
    while (temp) {
      temp /= 2;
      len++;
    }
    len--;  // we're decrementing len to skip checking the the Most significant bit, as it would be 1 in all the cases
    for (int i = len - 1; i >= 0; i--) {
      int bit = target & (1 << i);
      if (bit != 0 && curr->right)
        curr = curr->right;
      else if (bit == 0 && curr->left)
        curr = curr->left;
      else
        return false;
    }
    return true;
  }
};