/*  Greedy Approach is to find the most frequently occuring character, and seperate them with the second most frequently occuring character. And if we can do that, then it will gurantee us that no
    two similar characters are adjacent. So we basically need a DS, that allow us to know that this is the most frequently occuring character, this is the second most frequently character which 
    indicates toward max_heap.
    Similar to Schedule Task problem 

    TC: O(NLogA) where N is length of string, and A is size of alphabet set. If A is fixed like for lower/upper case then TC = O(N)
    Space: O(A) or O(1)

    Ex: "aabbcc" O/P = "cbacba" or "abcabc" or any possible valid
 */

class Solution 
{
public:
    string reorganizeString(string s) 
    {
        unordered_map<char, int> m;
        
        for(char c: s)
            {
                m[c]++;   //  Required string is only possible when char with max frequency is less than equal to half of size of given string.
                if(m[c] > (s.size()+1)/2)
                    return "";
            }

        priority_queue<pair<int, char>> q;
        for(auto it: m)
            q.push({it.second, it.first});
        
        string result="";
        
        while(q.size()>1)   //here we're checking for size>1, unlike typical >0 becz we've to extract pop() two elements from top
        {
            auto current = q.top();
                q.pop();
            result += string(1, current.second);
            
            auto next = q.top();
                q.pop();
            result += string(1,next.second);
            
            if(current.first>1)     // if we have more instances of character, then enqueue them again in max_heap
                q.push({current.first-1, current.second});
            if(next.first>1)
                q.push({next.first-1, next.second});
        }
        
        if(!q.empty())  //if we'are left with 1 character, and it has more than 1 instances then there's no way to seperate it, so return ""
        {
            if(q.top().first>1)
                return "";           
            result += string(1, q.top().second);
        }
        
        return result;
    }
};

/* Without using Sorting or Heap */
public class Solution 
{
    public string ReorganizeString(string s)
    {
        if (s == null || s.Length < 2)
            return s;
            
        int n = s.Length;
        
        // Calculate and store frequencies in char-frequency map.
        // Find character and frequency with max frequency
        int freqChar = -1;
        int freqCharCount = -1;
        int[] freq = new int[26];
        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] > freqCharCount)
            {
                freqCharCount = freq[s[i] - 'a'];
                freqChar = s[i] - 'a';
            }
        }
        
        // Required string is only possible when char with max frequency is less than equal to half of size of given string.
        if (freqCharCount > (n + 1) / 2)
            return "";
        
        StringBuilder str = new StringBuilder(s);
        int position = 0;
        // In case it is possible, arrange the most occuring character on even positions. 
        // Arrange the remaining characters on alternate remaining positions. 
        // This makes sure that no 2 same character occurs together.
        for (int i = -1; i < 26; i++)
        {
            int current = (i == -1) ? freqChar : i;
            while (freq[current]-- > 0)
            {
                str[position] = (char)('a' + current);
                position = (position + 2 >= n) ? 1 : position + 2;
            }
        }
        return str.ToString();
    }
}