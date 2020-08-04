/* 
    The number of set bits in an even number is same as that in it's half wheras in case of odd numbers it's one more than it's half.
    Because odd numbers have 1 as their LSB, so upon dividing it by 2 i.e >>1 would basically loose one number so we have to add one extra 1 wheras there is no such case for even number
*/

class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector<int> ans(num+1, 0);
        for(int i=0; i<=num; i++)
        {
            ans[i] = ans[i/2] + (i&1);
        }
        
        return ans;
    }
};