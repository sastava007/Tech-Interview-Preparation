/*  Idea is to use 2 pointers 'i' and 'j'.
    'i' to read characters from the string, and 'j' to write back to the character array.

    TC: O(N) and O(1) space

    Input: ["a","a","b","b","c","c","c","a"]  Output: a2b2c3a
    Edge Case: Input: ["a","b","x"]  Output: abx     here we didn't included no. otherwise length will become greater than original array, then there would be no point in compression
*/

class Solution {
public:
    int compress(vector<char>& chars) 
    {   
        if(chars.size()<2)
            return chars.size();
        
        int i=0, j=0;
        
        while(i<chars.size())   // 'i' to read the character array
        {
            char currentChar = chars[i];
            int count = 0;
            while(i<chars.size() && chars[i] == currentChar)    // find the no. times char has occurred
            {
                count++;
                i++;
            }
            
            chars[j++] = currentChar;  // write head will start writing from the 'j', if count = 1 then it will just write the 'character' and increment further
            
            if(count != 1)
            {
                for(char c: to_string(count))   // max time this loop will run is log10(N) 
                    chars[j++] = c;     // if count>1, then it will keep on writing each digit 
            }
        }
        return j;    // to get the resultant/modified vector<> just print all the characters till jth index 
    }
};