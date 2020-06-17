/*  Iterate the word, for each character, judge palindromic substrings by applying a fucntion palindrom. There are two cases, the
    palindromic string length is odd or even. For example aaa, aa. The fucntion palindrom checks from the 'center' to end. If the two
    character equals, move on, left pointer moves left, right pointer moves right, if not, break the loop.
    
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

/* Can be further optimized to solve in O(N) time using Manacher's algorithm */