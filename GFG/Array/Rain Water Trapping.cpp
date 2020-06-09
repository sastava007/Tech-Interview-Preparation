/*  
    Water will be collected b/w two boundaries, so basically we need to find the maximum greater element on left & right for each element 
    and amount of water will be bounded by minimum of two heights - height of building(elevantion).

    But this would require two extra arrays when solved using DP, but can be optimized further using 2 pointers that doesn't require any auxillary space.
    https://leetcode.com/articles/trapping-rain-water/ 
*/


#include <bits/stdc++.h>
using namespace std;

/* DP Solution: storing the maximum height on left & right of index */
int trap(vector<int>& height)
{
	if(height == null)
		return 0;

    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}

/* O(N) time, constant space solution. Intution similar to DP solution to find min(leftmax, rightmax)-height[i] */

class Solution {
public:
    int trap(vector<int>& height) 
    {
        if(height.size()==0)
            return 0;
        
        int left=0, right=height.size()-1, leftmax=0, rightmax=0;    
        int ans=0;
        while(left<right)
        {
            leftmax=max(leftmax, height[left]);
            rightmax=max(rightmax, height[right]);
            
            if(leftmax < rightmax)  //if leftmax is minimum then use it
            {
                ans += leftmax-height[left++];
            }
            else    //else if rightmax is minimum then it will bound the water so use it
            {
                ans += rightmax-height[right--];
            }
        }
        
        return ans;
    }
};