/* 
    Count number of pallindromic substrings  

    1. There are total (N(N-1))/2 substrings and to we can generate them in O(N2) and to check whether they are pallindrome or not wil take O(N) time.
    So total complexity will be O(N^3).

    2. We can optimize the process of checking whether a given string is pallindrome or not to O(1) by storing the precomputed result, s[i..j] is pallindrome
    if s[i] == s[j] and s[i+1....j-1] is already a pallindrome. TC & Space: O(N^2) Dynamic Programming

    3. We can further optimize the space by using a clever method of 'Expand Around Center' in which we check for odd & even length substrings
    TC: O(N^2) and Space: O(N)
*/

class Solution {
public:
    int countSubstrings(string s) 
    {
        int result = 0, n = s.size();
        if(n == 0)
            return 0;
        
        bool isPallindrome[n][n];
        
        memset(isPallindrome, false, sizeof(isPallindrome));
        for(int i=0; i<n; i++)      // all pallindromes of length 1
            isPallindrome[i][i] = true;
        
        for(int i=0; i<n-1; i++)    // all pallindromes of length 2
            if(s[i] == s[i+1])
                isPallindrome[i][i+1] = true;
        
        for(int k = 3; k<=n; k++)   // pallindrome of length k
        {
            for(int i=0; i<n-k+1; i++)
            {
                int j = i+k-1;
                if(s[i] == s[j] && isPallindrome[i+1][j-1])
                    isPallindrome[i][j] = true;
            }
        }
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(isPallindrome[i][j])
                    result++;
        return result;
    }
};

/* Expand Around Center TC: O(N^2) and Space: O(1) */

class Solution {
public:
    int countSubstrings(string s) 
    {
        if(s.size() == 0)
            return 0;
        int result = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            expandAroundCenter(s, i, i, result);
            expandAroundCenter(s, i, i+1, result);
        }
        return result;
    }
private:
    void expandAroundCenter(string s, int l, int r, int &result)
    {
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            l--;
            r++;
            result++;
        }
    }
};