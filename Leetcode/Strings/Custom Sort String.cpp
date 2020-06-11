/*  Idea is to build a hash map containing the freq of each character of T, and as we've to sort the string T based on ordering of S. Then we can just start iterating from T, and add all elements
    which are presnt in S. And later add all the reamining characters, that are still pedning to be added.
*/

class Solution {
public:
    string customSortString(string S, string T) 
    {
        vector<int> hash(26, 0);
        
        for(char c: T)
            hash[c-'a']++;
        
        string res;
        
        for(char c: S)
        {
            while(hash[c-'a']-- > 0)
                res += c;
        }
        
        for(char c='a'; c<='z'; c++)
            while(hash[c-'a']-- > 0)
                res += c;
        
        return res;
        
    }
};