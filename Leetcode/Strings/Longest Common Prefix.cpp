/*  */

// Vertical Scannning   TC: O(S) and Space: O(1) where S is sum of all characters in string 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.empty())
            return "";
        
        if(strs.size()==1)
            return strs.back();
        
        string res = "";
        int len = INT_MAX;
        for(string s: strs)
            len = min(len, (int)s.length());
        
        for(int i=0; i<len; i++)
        {
            for(int j=1; j<strs.size(); j++)
                if(strs[j][i] != strs[0][i])
                    return res;
            
            res += strs[0][i];
        }
        
        return res;
    }
};

/* 
    Using Binary Search: Do BS on length of LCP as we know that upper bound will be min(s[0].length(), s[1].length()...) 
    TC: O(S*logM)
    where M is minimum length string
*/
public String longestCommonPrefix(String[] strs) 
{
    if (strs == null || strs.length == 0)
        return "";
    int minLen = Integer.MAX_VALUE;
    for (String str : strs)
        minLen = Math.min(minLen, str.length());
    int low = 1;
    int high = minLen;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (isCommonPrefix(strs, middle))
            low = middle + 1;
        else
            high = middle - 1;
    }
    return strs[0].substring(0, (low + high) / 2);
}

private boolean isCommonPrefix(String[] strs, int len){
    String str1 = strs[0].substring(0,len);
    for (int i = 1; i < strs.length; i++)
        if (!strs[i].startsWith(str1))
            return false;
    return true;
}

/* Another Approach: using Trie */