/*
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

*/

class Solution {
public:
  
  int countVowelStrings(int n) {
        
  int table[52][52] = { 0 };
	
  table[0][0] = 1;
	for (int i = 1; i < 5; i++)
		table[0][i] = table[0][i - 1] + 1;
	
	for (int i = 0; i < n; i++)
		table[i][0] = 1;


	
	for (int i = 1; i < n; i++)
		for (int j = 1; j < 5; j++)
			table[i][j] = table[i - 1][j] + table[i][j - 1];
		
	return table[n - 1][4];
        
        
  }
};
