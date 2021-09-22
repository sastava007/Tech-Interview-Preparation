/*
    We've to find if we can make a palindrome from substring in range[i,j] by rearranging characters and replacing atmost K characters.
    And since we can rearrange chars we're sured that chars with even freq will be set, and only need to work with those with odd freq. So we count no. of unique chars with odd freq
    and replaces half of them with different char.
    
    We need to find the number of odd occurences of characters in the range left,right efficiently
    We only need to maintain parity sum, as we need to find only number of characters which are present odd times in given range.
    And to get no. of characters with odd frequency in range [i..j]  = countOfSetBits(paritySum[i-1] ^ paritySum[j]) 

    Example: "abcdaba" use XOR to calculate parity letter by letter
    [00000000(""), 00000001("a"), 00000011("ab"), 00000111("abc"), 00001111("abcd"), 00001110("abcda"), 00001100("abcdab"), 00001101("abcdaba")]
*/

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) 
    {
        int mask = 0;
        vector<bool> result;
        vector<int> paritySum(1);
        for(char c: s)
            paritySum.emplace_back(mask ^= (1<<(c-'a')));   // bit will be set only if character is present odd no. of times
        
        for(auto query: queries)
        {
            int odd = __builtin_popcount(paritySum[query[0]] ^ paritySum[query[1]+1]);
            odd/2 <=query[2] ? result.emplace_back(true):result.emplace_back(false);
        }
        return result;
    }
};