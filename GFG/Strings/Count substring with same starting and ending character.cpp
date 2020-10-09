/* 
    Maintain freq. of characters, and then pick (freq+1)C2
    TC: O(N)
*/

int countSubstringWithEqualEnds(string s) 
{ 
    int result = 0; 
    int n = s.length(); 
  
    // Calculating frequency of each character in the string. 
    int count[26] = {0}; 
    for (int i=0; i<n; i++) 
        count[s[i]-'a']++; 
    
    for (int i=0; i<26; i++)  // Computing result using counts 
        result += (count[i]*(count[i]+1)/2); 
  
    return result; 
}

/* Bruteforce Solu: Here 'i' and 'j' represents the starting and ending character of string */
int countSubstringWithEqualEnds(string s) 
{ 
    int result = 0; 
    int n = s.length(); 
  
    // Iterating through all substrings in way so that we can find first and last character easily 
    for (int i=0; i<n; i++) 
        for (int j=i; j<n; j++) 
            if (s[i] == s[j]) 
                result++; 
  
    return result; 
} 