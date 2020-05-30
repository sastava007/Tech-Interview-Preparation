#include<bits/stdc++.h>
using namespace std;

bool isOneEdit(string s, string t)
{
    int m = s.length(), n = t.length();
        if(abs(m-n)>1)
            return false;
    
    int i=0, j=0, edit=0;

    while(i<m && j<n)
    {
        if(s[i] != t[j])
        {
            edit++;
            if(edit>1)
                return false;
            
            if(m>n) //if s is longer string, then delete character from s
                i++;
            else if(n>m)    //if t is longer string, then delete character from t
                j++;
            else    //if both are having same length. then increment the positions for both the strings
            {
                i++;
                j++;
            }
            
        }else
        {
            i++;
            j++;
        }
    }

    if(i<m || j<n)  //if one string is just one element greter than other, then in that case the itertaor for longer one has to be terminated before
        edit++;

    return (edit==1);
}

/* O(n) Solution */
public boolean isOneEditDistance(String s, String t) {
   int m = s.length(), n = t.length();
   if (m > n) return isOneEditDistance(t, s);
   if (n - m > 1) return false;
   int i = 0, shift = n - m;
   while (i < m && s.charAt(i) == t.charAt(i)) i++;
   if (i == m) return shift > 0;
   if (shift == 0) i++;
   while (i < m && s.charAt(i) == t.charAt(i + shift)) i++;
   return i == m;
}