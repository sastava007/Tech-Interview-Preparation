/* Strobogrammatic Number is the number which is rotationally symmetric, i.e same when rotated 180deg */
/*  Check if given number is Strobogrammatic or not

    Note: Confirm about the leading zeroes number, like whether 00 is a strobogrammatic or not.
    Edge Cases: [000 => true, 080 => true, 060 => false, 0690 => true, 06690 => false]
*/

bool isStrobogrammatic(string nums)
{
    unordered_map<char,char> m;
    m['0']='0';
    m['1']='1';
    m['6']='9';
    m['8']='8';
    m['9']='6';

    int l=0,r=nums.length()-1;

    while(l<=r && nums[l]=='0')  //case to handle leading zeroes: remove the leading zeroes
        l++;
    if(l==r)
        return (nums.length()==1);

    while (l<=r)
    {
        if(m.find(nums[l])==m.end() || m.find(nums[r])==m.end() || m[nums[l]] != m[r])
            return false;
        l++;
        r--;
    }

    return true;
}

/*  Return all Strobogrammatic Number of length n: Backtracking Solution
    TC: O(5^N)
*/

class Solution
{
    public:
    unordered_map<char,char> m;
    m['0']='0';
    m['1']='1';
    m['6']='9';
    m['8']='8';
    m['9']='6';

    vector<string> findStrobogrammatic(int n)
    {
        vector<string> res;
        if(n<1)
            return res;

        helper(0,n-1,"",res);

        return res;
    }

    void helper(int low, int high, string s, vector<string> &res)   
    {
        if(low>high)    //base case: push the no. formed so far into the result array
        {
            if(s.length()==1 || s[0]!='0')  // to avoid leading zeroes, like incase of 00
                res.push_back(s);
            return;
        }

        for(auto it: m)
        {
            if(low==high && it.first!=it.second)
                continue;
                
            s[low]=it.first;    
            s[high]=it.second;
            helper(low+1, high-1, s, res);
        }   
    }
};
