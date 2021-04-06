/* 
    So idea is to generate odd & even length substrings around a center point, and for each of them find the maximum length.
        1. To generate odd length palindrome, Fix a centre and expand in both directions for longer palindromes, center = i, low = i-1 and high = i+1
        2. similarly for even length pallindrome, center = i, low = i-1 and high = i
    
    There can be total 2N-1 possible center, N for all charceters as ceneter in case of ODD length pallindromic string, and N-1 centers 
    in b/w 2 characters for even length pallindromic string.

    TC: O(N^2) and O(1) Space
*/

string longestPalindrome(string s)
{
    if(s.length()==0)
        return "";
    
    int n = s.length(), low, high, start=0, maxlen = 1;       // All substrings of length 1 are palindromes 
    for(int i=0; i<n; i++)   // point around which to center
    {
        low = i-1, high = i+1;        //check for odd length substring, centered around i
        while(low>=0 && high<n && s[low]==s[high])
        {
            if(high-low+1 > maxlen)
            {
                start = low;
                maxlen = high-low+1;
            }
            high++;
            low--;
        }

        low = i-1, high = i;      //check for even length substring, centered around i
        while(low>=0 && high<n && s[low] == s[high])
        {
            if(high-low+1 > maxlen)
            {
                start = low;
                maxlen = high-low+1;
            }
            high++;
            low--;
        }
    }
    return s.substr(start, maxlen);
}

/* We can also solve this using a DP approach, but that requires an O(N^2) extra space */

int longestPalSubstr(string str) 
{
    int n = str.size(); 

    bool table[n][n];       // table[i][j] represents whether substring b/w ith & jth indexes are pallindrome or not
    memset(table, false, sizeof(table)); 
  
    // All substrings of length 1 are palindromes 
    int maxLength = 1; 
  
    for (int i = 0; i < n; ++i)     // fill around the diagonal
        table[i][i] = true;
  
    // check for sub-string of length 2. 
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true; 
            start = i; 
            maxLength = 2; 
        }
    } 

    // Check for lengths greater than 2, here K is length of substring
    for (int k = 3; k <= n; k++) { 
        // Fix the starting index 
        for (int i = 0; i < n - k + 1; i++) {   // starting from index 'i' and length K

            int j = i + k - 1;
  
            // checking for sub-string from ith index to 
            // jth index iff str[i+1] to str[j-1] is a 
            // palindrome 
            if (table[i + 1][j - 1] && str[i] == str[j]) { 
                table[i][j] = true; 
  
                if (k > maxLength) {
                    start = i; 
                    maxLength = k; 
                }
            } 
        } 
    }
}