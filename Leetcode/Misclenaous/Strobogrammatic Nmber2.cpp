/* Time complexity: O(5^n) */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

     unordered_map<char, char> m;
     
     void init()
     {
         m['0']='0';
         m['1']='1';
         m['6']='9';
         m['9']='6';
         m['8']='8';
     
     }
    
    vector<string> findStrobogrammatic(int n) 
    {
        vector<string> res;
        
        if(n<1)
            return res;
        init();
        string s("",n);
        
        helper(0, n-1, s, res);
        
        return res;
    }
    
    void helper(int low, int high, string s, vector<string> &res)
    {
        if(low>high)    //base case
        {
            if(s[0]!='0' || s.length()==1)
                res.push_back(s);
            
            return;
        }
        
        for(auto it: m)
        {
            if(low==high && it.first!=it.second)    //when low=high, means we've just 1 place lefy then it can't be 6 or 9 becz they are not strobogrammatic to themselves. 
                continue;
                
            s[low]=it.first;
            s[high]=it.second;
            
            helper(low+1, high-1, s, res);
        }
    }
};

int main()
{

    Solution obj;
    vector<string> res = obj.findStrobogrammatic(2);

    for(auto it: res)
        cout<<it<<" ";
        
    return 0;
}