/*  Find longest substring, such that all the elements in that substring has occurred atleast K times 
    For i = [1,26], we are going to use sliding window (left i, right j) to find the "longest window which contains exactly h unique characters and for each character, there are at least K repeating times".

    TC: O(N*26) => O(N) and Space: O(26) due to recursive calls which will go 26 level deep
*/

class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int maxlen = 0;
        for(int i=1; i<=26; i++)
        {
            maxlen = max(maxlen, longestSubstringWithNUniqueChars(s,i,k));
        }
        return maxlen;
    }
    
private: 
    int longestSubstringWithNUniqueChars(string s, int totalUnique, int k)  // maximum length of substring, which contains exactly H 'totalUnique' characters and
                                                                           // each of them has occurred atleast K times
    {
        unordered_map<char, int> m;
        int begin=0,end=0,unique=0,numNoLessThanK=0,maxlen=0;
        while(end<s.length())
        {
            m[s[end]]++;
            if(m[s[end]]==1)    // no. of unique characters
                unique++;
            if(m[s[end]]==k)    // if dreq of that character becomes equal to K, increment the  numNoLessThanK
                numNoLessThanK++;
            end++;
            
            while(unique>totalUnique)
            {
                if(m[s[begin]]==k)  //if current character is present exactly K times then after slding the window, it wil not remain K times, so drecase 'numNoLessThanK'
                    numNoLessThanK--;
                
                m[s[begin]]--;
                if(m[s[begin]]==0)
                    unique--;   
                
                begin++;
            }
            if(unique==totalUnique && numNoLessThanK==unique)   // 2nd part means that, no. of unique characters in substring should be equal to the no. of characters which have freq>=k
                maxlen = max(maxlen, end-begin);
        }
        return maxlen;
    }
};

/*  Using D&C
    So idea is to use D&C based approach which will return the length of longest substring in which all the characters are occuring atleast K times.
    So whenever we find a character which is having freq <K, we'll break the string into 2 smaller substrings. We'll recursively call for them and return the maximum of length returned by them.
    TC: O(N) and Space: O(N) due to recursive (doubtful, maybe N^2)

    We can observe here that, once we find a chars which is having freq < K, then it will be used to divide the string and all the substrings in the further recursive calls will not contain
    that character. The level of D&C is at most 26, otherwise you run out of character to divide, and each level is O(n).
*/

class Solution 
{

public:

    int longestSubstring(string& s, int k)
    {
        return util(s, k, 0, s.size());
    }

    int util(string& s, int k, int start, int end)
    {
        vector<int> freq(26);
        for (int i = start; i < end; i++)
            freq[s[i]-'a']++;

        int idx = start;
        while (idx < end)
        {
            if (freq[s[idx]-'a'] < k)
                break;
            ++idx;
        }

        if(idx == end)          // if all the chars are having freq >=K
            return idx - start;

        int right_start = idx + 1;
        while(right_start < end && freq[s[right_start]-'a'] < k)        // first part starts from beginning, and till the first index which has freq <K
            right_start++;

        return max(util(s, k, start, idx), util(s, k, right_start, end));   // second part starts from the first point which is having freq >=K and till the end 
    }
};