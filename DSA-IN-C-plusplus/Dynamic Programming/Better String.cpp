// User function Template for C++

class Solution {
  public:
  
    int countSub(string str) {
        vector<int> last(127, -1);
        int n = str.length();
        int dp[n + 1];
     
        dp[0] = 1;
     
        for (int i = 1; i <= n; i++) {
            dp[i] = 2 * dp[i - 1];
     
            if (last[str[i - 1]] != -1)
                dp[i] = dp[i] - dp[last[str[i - 1]]];
     
            last[str[i - 1]] = (i - 1);
        }
        return dp[n];
    }
    string betterString(string str1, string str2) {
        // code here
        if(countSub(str1) < countSub(str2)) return str2;
        
        return str1;
    }
};
