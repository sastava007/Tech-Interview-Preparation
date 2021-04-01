/*
    TC & Space: O(logN)

    The range of values present at level 'i' (considering root node as 1) is given by 2^(i-1) - 2^i-1
    
    Also the level at which a current label belong can be computed using a while loop, or log2(n)+1
    
    In a simple ordered tree, parent is given by label/2. But in case of zig-zag tree we need to find the
    inversion or it's equivalent value in normal tree, which basically means that we need to translate 14 
    to 9 which can be done by observing 15+8 = 14+9 = 13+10 = 12+11 = 23, 
    i.e if we add the maximum + minimum node at each level and subtract the current label we'll get it's 
    equivalent label in simple ordered tree.
    
    Further which just divide by 2, and we got it's parent node.
*/

class Solution {
public:
    vector<int> pathInZigZagTree(int label, int level = 0) 
    {
        while(1<<level <= label)
            level++;
        
        vector<int> result(level);
        
        for(int i = level; i>0; i--)
        {
            result[i-1] = label;
            int left = 1<<(i-1);
            int right = (1<<i)-1;
            label = (left+right-label)/2;
        }
        return result;
    }
};