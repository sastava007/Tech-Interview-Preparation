/*  Bruteforce: O(N^3)

    Generating all the possible substrings and for all the substrings check it for the remaining string if there exists an identical substring. There are O(n2) total substrings and checking them against the remaining string will take O(n) time. So overall time complexity of above solution is O(n3).
*/

int maxlen = 0;
for(int i=1; i<n-1; i++)
{
    for(int j=i+1; j<n; j++)
    {
        int k = 0;
        while(s[i+k]==s[j+k])
        {
            k++;
            maxlen = max(maxlen, k);
        }
    }
}

/*  Find the 'length' of the longest repeating substring, here substrings can even overlap. 
    dp[i][j] represents the length of the matching substring ending with ith and jth characters
    So if str[i-1]==str[j-1] then dp[i][j] = dp[i-1][j-1]+1 and we have to keep on finding the maximum of these values
    TC & Space: O(N^2) 

    Input = "aabcaabdaab" ans = 3(aab)
    Edge Case = "aaaaa"  ans = 4(aaaa) , here we're also considering overlapping substrings also

*/

int longestRepeatingSubstring(string s)
{
    if(s.length()==0)
        return 0;

    int n = s.length(), maxlen=0;
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int i=1; i<=n; i++)
    for(int j=1; j<i; j++)
    {
        if(s[i-1] == s[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;

        maxlen = max(maxlen, dp[i][j]);
    }

    return maxlen;
}

/*  To get the longest repeating substring, that doesn't overlap we've to make sure that the length of suffix should be smaller than (j-i). 
    So just add (str[i-1]==str[j-1] && dp[i-1][j-1]<j-i)

    We can also find the actual substring, by noting down the ending index and length of substring
*/

    for(int i=1; i<=n; i++) 
	{ 
		for (int j=1; j<i; j++) 
		{ 
			if (str[i-1] == str[j-1] && LCSRe[i-1][j-1] < (j-i)) 
			{ 
				LCSRe[i][j] = LCSRe[i-1][j-1] + 1; 

				if (LCSRe[i][j] > res_length) 
				{ 
					res_length = LCSRe[i][j]; 
					index = max(i, index); 
				} 
			} 
			else
				LCSRe[i][j] = 0; 
		} 
	}
	if (res_length > 0) 
		for (i = index - res_length + 1; i <= index; i++) 
			res.push_back(str[i-1]); 