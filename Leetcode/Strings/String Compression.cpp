/*  Idea is to use 2 pointers 'i' and 'j'.
    'i' to read characters from the string, and 'j' to write back to the character array.

    TC: O(N) and O(1) space
*/

class Solution {
public:
    int compress(vector<char>& chars) 
    {   
        if(chars.size()<2)
            return chars.size();
        
        int i=0, j=0;
        
        while(i<chars.size())       // 'i' to read the character array
        {
            chars[j]=chars[i];
            int count = 0;
            while(i<chars.size() && chars[i]==chars[j])     // find the no. times char has occurred
            {
                count++;
                i++;
            }
            
            if(count==1)        // if we have just 1 instance of that character, then no need to write back to original array ex: a1 doesn't make any sense
                j++;
            else
            {
                for(char c: to_string(count))   // if counter is more than one digit, like if 'a' has occurred 10 times then a10 
                    chars[++j] = c;
                
                j++;    // move to the next place, where we need to write
            }
        }
        
        return j;
    }
};