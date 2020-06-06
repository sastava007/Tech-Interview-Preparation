/* Inspired from substring search using sliding window and hashMap LC template */

class Solution {
public:

    int lengthOfLongestSubstringTwoDistinct(string &s) 
    {
        unordered_map<char, int> m;
        int begin=0, end=0, n=s.length(), maxlen=0;
        int distinct=0;
        
        
        while(end<n)
        {
            m[s[end]]++;
            if(m[s[end]]==1)    //when freq of a char is 1: it represents new character(distinct)
                distinct++;
            end++;
            
            while(distinct>2)
            {
                m[s[begin]]--;
                if(m[s[begin]]==0)  //when frequency of a character becomes 0, then it means total distinct character should also be dcreased by 1
                    distinct--;
                begin++;
            }
            maxlen=max(maxlen, end-begin);
        }
        
        return maxlen;
    }
};

/* We can also use the size of the map as a mesure of distinct characters */
public int lengthOfLongestSubstringKDistinct(String s, int k) 
{
        if (s == null || s.isEmpty()) 
            return 0;
        int maxLen = 0, left = 0, right = 0, counter = 0;
        Map<Character, Integer> map = new HashMap<>();
        while(right < s.length()) 
        {
        	char ch = s.charAt(right++);
        	map.put(ch, map.getOrDefault(ch, 0) + 1);
        	if (map.size() > k) counter++;
        	while(counter > 0) {
        		char tmp = s.charAt(left);
        		map.put(tmp, map.get(tmp) - 1);
        		if (map.get(tmp) == 0) {
        			map.remove(tmp);
        			counter--;
        		}
        		left++;
        	}
        	maxLen = Math.max(maxLen, right - left);
        	
        }
        return maxLen;        
    }