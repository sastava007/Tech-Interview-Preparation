/*  Idea is to build a hash map containing the freq of each character of T, and as we've to sort the string T based on ordering of S. Then we can just start over S, and add all elements
    which are also presnt in T. And later add all the reamining characters, that are still pedning to be added which were not present in string S.
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

/* Optimized Version: Without using while loop */
class Solution {
public:
    string customSortString(string S, string T) 
    {
        vector<int> hash(26, 0);
        for(char c: T)
            hash[c-'a']++;
        
        string res;
        for(char c: S)      //add all the characters which are present in string S in the same order as they are in S
        {
            res += string(hash[c-'a'], c);
            hash[c-'a']=0;
        }
        
        for(char c='a'; c<='z'; c++)    //add all the remaining characters of string T which were not present in S
        {
            if(hash[c-'a']>0)
            {
                res += string(hash[c-'a'], c);
            }
        }
        return res;
    }
};