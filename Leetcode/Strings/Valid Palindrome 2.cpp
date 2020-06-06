/*  Remove atmost 1 element and check if palindrome. 
    A string is pallindrome if left==right(odd) or left>right(even) , or after removing left element or after removing right element.
*/


class Solution {
public:
    bool validPalindrome(string s) 
    {
        int i = 0, j = s.length()-1;
        
        while(i<=j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                //remove or skip the left element
                int l = i+1, r = j;
                while(l<=r && s[l]==s[r])
                {
                    l++;
                    r--;
                }
                if(l>=r)
                    return true;
                
                //remove or skip the right element
                l = i, r = j-1;
                while(l<=r && s[l]==s[r])
                {
                    l++;
                    r--;
                }
                if(l>=r)
                    return true;
                
                return false;   //if after removing left & right element, the string isn't palindrome then it can't be a palindrome.
            }
        }
        
        return true;
    }
};