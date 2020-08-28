/* 
    Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
    
    So idea is to store the string by reversing in a hash map, and for each string split it into left & right substrings and check for each part individually. So if there exists a candidate
    in map which is equal to the left part, (means it reverse in original) like if left = "abcd" and if there exists abcd in map too, which means there exists dcba in original string. So what
    we can do it, we can concatenate dcba to left part and it would look something like this. 
    [abcd + right] + dcba, so here our right part should also need to be a pallindrome in itself. Similarly check for right part.

    In: ["abcd","dcba","lls","s","sssll"]    Out: [[0,1],[1,0],[3,2],[2,4]]  =>  ["dcbaabcd","abcddcba","slls","llssssll"]
    Edge Case: when there is empty word ex {"a", ""}, then we need to have both [0,1] as well as [1,0]

    TC: O(N*K^2) where N is total no. of words in dictionary and K is length of maximum word
*/

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>> result;
        if(words.size()==0)
            return result;
        
        unordered_map<string, int> dict;
        int n = words.size();
        for(int i=0; i<n; i++)
        {
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            dict[temp] = i;
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<words[i].length(); j++)
            {
                string left = words[i].substr(0,j);
                string right = words[i].substr(j);
                
                if(dict.find(left)!=dict.end() && dict[left]!=i && isPallindrome(right))
                {
                    result.push_back({i, dict[left]});
                    if(left=="")    // Here we're checking this case explicity for "" string case in word list
                        result.push_back({dict[left], i});
                }
                
                if(dict.find(right)!=dict.end() && dict[right]!=i && isPallindrome(left))   // We aren't doing the same explicit check over here becz right can never me ""
                {                                                                           // as we're looping till  < word.length()
                    result.push_back({dict[right], i});
                }
            }
        }
        return result;
    }

private:
    bool isPallindrome(string s)
    {
        int i=0, j=s.length()-1;
        while(i<j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
};