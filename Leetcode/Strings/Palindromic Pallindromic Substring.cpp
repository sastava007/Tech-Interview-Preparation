/*  Iterate the word, for each character, judge palindromic substrings by applying a fucntion palindrom. There are two cases, the
    palindromic string length is odd or even. For example aaa, aa. The fucntion palindrom checks from the 'center' to end. If the two
    character equals, move on, left pointer moves left, right pointer moves right, if not, break the loop.
    
    1. Expand Around Centre
        O(N^2 time) and O(1) space
        Worst Case: "aaa" => ["a", "a", "a", "aa", "aa", "aaa"]

*/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            palindromic(s, i, i, cnt);      //judge odd substring
            palindromic(s, i, i+1, cnt);    //judge even substring
        }
        return cnt;
    }
    
private:
    void palindromic(string s, int left, int right, int& cnt) 
    {   
        while(left >=0 && right < s.size() && s[left] == s[right])   //judge if a substring is palindromic
        {
            cnt++;
            left--;
            right++;
        }
    }
};

/* Using DP:   Time & Space O(N^2)  */

int countSubstrings(String s) 
{
    if (s.isEmpty())
        return 0;

    int n = s.length();

    boolean[][] dp = new boolean[n][n];

    int count = 0;

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        count++;
    }

    int i, k, j;

    // check for sub-string of length 2
    for (i = 0; i < n - 1; i++) {
        if (s.charAt(i) == s.charAt(i + 1)) {
            dp[i][i + 1] = true;
            count++;
        }
    }

    for (k = 3; k <= n; k++) {
        // i is the starting index
        for (i = 0; i < n - k + 1; i++) {
            // j is ending index of substring from starting index i and length k
            j = i + k - 1;
            if (dp[i + 1][j - 1] && s.charAt(i) == s.charAt(j)) {
                dp[i][j] = true;
                count++;
            }
        }
    }
    return count;
}


/* Can be further optimized to solve in O(N) time using Manacher's algorithm */