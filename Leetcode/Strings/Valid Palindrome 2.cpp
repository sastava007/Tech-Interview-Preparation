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
                int l = i+1, r = j;             //remove or skip the left element
                while(l<=r && s[l]==s[r])
                {
                    l++;
                    r--;
                }
                if(l>=r)
                    return true;
                l = i, r = j-1;                 //remove or skip the right element
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

/*  Follow Up: Is the given word is a K-Pallindrome or not, means given string can be transformed into pallinfrome by removing atmost K characters 
    
    So idea is to first find the length of longest pallidrome substring in s, and then subtract its lengths from the total length of the string if this difference is <=K, then it is possible.
    This would work becz if the maximum length pallindrome is having a diff. of more than K characters then we need to delte more than K characters then it is not possible.

    TC: O(N^2) and Space: O(1)
*/
bool isKPallindrome(string s, int k)
{
    int n = s.length();
    if(n==0 || n<=k)        // if emppty string, or if it has <=K characters then remove all of them & we'll end up getting an empty string which is a pallindrome
        return true;

    int maxlenPallindrome = longestPallindromeLength(s);
    return (n-maxlenPallindrome <= k)

}

int longestPallindromeLength(string s)
{
    if(s.length()==0)
        return 0;

    int n = s.length(), maxlen = 1, low, high;
    for(int i=1; i<n; i++)      // point around which to center
    {
        low = i-1, high = i;        //check for even length substring, centered around i
        while(low>=0 && high<n && s[low]==s[high])
        {
            maxlen = max(maxlen, high-low+1);
            high++;
            low--;
        }

        low = i-1, high = i+1;      //check for odd length substring, centered around i
        while(low>=0 && high<n && s[low]==s[high])
        {
            maxlen = max(maxlen, high-low+1);
            high++;
            low--;
        }
    }
    return maxlen;
}