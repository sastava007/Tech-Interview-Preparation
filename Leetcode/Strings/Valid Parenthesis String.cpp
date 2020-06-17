/* 
    Let diff be count of left parenthesis - count of right parenthesis. And Diff here should always be non-negative, becz we can't have more closing brackets than opening one
    When we meet:

    (, we increment diff.
    ), we decrement diff.
    *, we have three choices which makes the diff become a range [diff - 1, diff + 1].

    So we use maxDiff/minDiff to record the maximum/minimum diff we can get.
    When we meet:

    (, ++maxDiff and ++minDiff.
    ), --maxDiff and --minDiff.
    *, ++maxDiff and --minDiff.

    If maxDiff become negative, it means it's already invalid, we should return false. Becz this shows that no. of closing brackets is way to greter than opening brackets & 
    even * can't compensate for this.
    https://leetcode.com/problems/valid-parenthesis-string/discuss/302732/C%2B%2B-O(S)-Time-O(1)-Space-One-Pass-with-Explanation 
*/

class Solution {
public:
    bool checkValidString(string s) 
    {
        int minDiff=0, maxDiff=0;
        for(char &c: s)
        {
            if(c=='(')
            {
                maxDiff++;
                minDiff++;
            }
            else if(c==')')
            {
                maxDiff--;
                minDiff--;
            }
            else    //when * is encountered
            {
                maxDiff++;
                minDiff--;
            }
            
            if(maxDiff<0)   
                return false;
            minDiff=max(0, minDiff);    // Whenever minDiff falls below 0, we should force it to be 0 because we never accept negative diff during the process.
        }
        
        return (minDiff==0);
    }
};