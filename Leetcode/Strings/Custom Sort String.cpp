/*  Idea is to build a hash map containing the freq of each character of T, and as we've to sort the string T based on ordering of S. Then we can just start over S, and add all elements
    which are also presnt in T. And later add all the reamining characters, that are still pedning to be added which were not present in string S.

    Note: S has no no repitions, but not sure about T. (confirm from interviewer)
    TC: O(N+M) and O(1) Space

    Edge Cases: 
    1. Think of cases when 'S' has all distinct characters, but 'T' has repititions, so in such cases for any x which occurs before y in S, there shouldn't be an instance of it
                which comes after y in T.
                s = "cba"   t = "cdabcca"  =>  result = "cccbaad"
    2. Consider the case, when a particular character is present in 'S' but not in 'T' like  
                s = "cbxa"   t = "cdabcca"  =>  result = "cccbaad"

*/

class Solution {
public:
    string customSortString(string S, string T) 
    {
        vector<int> hash(26, 0);
        
        for(char c: T)
            hash[c-'a']++;
        
        string res;
        
        for(char c: S)                  //add all the characters which are present in string S in the same order as they are in S
        {
            while(hash[c-'a']-- > 0)
                res += c;
        }
        
        for(char c='a'; c<='z'; c++)    //add all the remaining characters of string T which were not present in S
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