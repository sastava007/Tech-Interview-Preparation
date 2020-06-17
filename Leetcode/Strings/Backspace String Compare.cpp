/* As backspace will delete the characters after which they will come, so idea is to start traversing from the back and maintain the no. of characters to skip/delete 
    TC: O(N+M) ; Space: O(1)
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        int i=s.length()-1, j=t.length()-1;
        int sSkip = 0, tSkip = 0;
        
        while(i>=0 || j>=0)
        {
            while(i>=0)
            {
                if(s[i]=='#')
                {
                    sSkip++;
                    i--;
                }
                else if(sSkip>0)    // skip all the characters that will be deleted by the backspace
                {
                    sSkip--;
                    i--;
                }
                else
                    break;
            }
            while(j>=0)
            {
                if(t[j]=='#')
                {
                    tSkip++;
                    j--;
                }
                else if(tSkip>0)    // skip all the characters that will be deleted by the backspace
                {
                    tSkip--;
                    j--;
                }
                else
                    break;
            }
            
            if(i>=0 && j>=0 && s[i]!=t[j])  // if after skipping all characters we reach at a posistion, and there characters aren't equal then return false, becz they can't be skipped anymore
                return false;
            
            if(i>=0 != j>=0)
                return false;
            
            i--;
            j--;
            
        }
        
        return true;
    }
};