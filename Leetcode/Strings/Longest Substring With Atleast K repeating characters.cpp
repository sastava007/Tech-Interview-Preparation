/*  Find longest substring, such that all the elements in that substring has occurred atleast K times 
    For i = [1,26], we are going to use sliding window (left i, right j) to find the "longest window which contains exactly h unique characters and for each character, there are at least K repeating times".

    TC: O(N*26) => O(N) and Space: O(26) due to recursive calls which will go 26 level deep
*/

class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int maxlen = 0;
        for(int i=0; i<26; i++)
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
                if(m[s[begin]]==k)  //if current character is present K times then after slding the window, it wil not remain K times, so drecase 'numNoLessThanK'
                    numNoLessThanK--;
                
                m[s[begin]]--;
                if(m[s[begin]]==0)
                    unique--;   
                
                begin++;
            }
            if(unique==totalUnique && numNoLessThanK==unique)
                maxlen = max(maxlen, end-begin);
        }
        return maxlen;
    }
};

/*  Using D&C
    Idea is to recursively keep on decreasing the range of the string, by forming smaller substrings such that all the elemenets in that range occurs atleast K times. And we do this by picking an element to divide the string, then all the substrings in following recursive call doesn't have that character.

    TC: O(N) and Space: O(26/N) due to recursive (doubtful, maybe N^2)
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        return helper(s, 0, n-1, k);
    }
private:
    // looking for longest string within index range [l, r]
    int helper(string& s, int l, int r, int k) {
        vector<int> mp(26, 0);
        for (int i = l; i <= r; i++)
            mp[s[i]-'a']++;

       // check if all the characters in this substring are present atleast K times
        bool pass = true;
        for (int i = 0; i < 26 && pass; i++) {
            if (mp[i] && mp[i] < k)     // if that character is present but less than minimum requirement
                pass = false;
        }
        if (pass) 
            return r-l+1;

        // using all characters with occurrence > 0 && < k to divide the string
        int i = l, ans = 0;
        for (int j = l; j <= r; j++) 
        {
            if (mp[s[j]-'a'] && mp[s[j]-'a'] < k)   // divide around the character, which have freq < K
            {
                ans = max(ans, helper(s, i, j-1, k));
                i = j+1;
            }
        }
        return max(ans, helper(s, i, r, k));
    }
};