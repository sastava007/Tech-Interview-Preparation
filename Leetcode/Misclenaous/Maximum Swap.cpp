/*  You can just perform 1 swap operation, so find the maximum no. formed after 1 swap. 
    
    Use hash/bucket to record the last position of digit 0 ~ 9 in this num.
    Loop through the num array from left to right. For each position, we check whether there exists a larger digit in this num (start from 9 to current digit). We also need to make sure the position of this larger digit is behind the current one. If we find it, simply swap these two digits and return the result.

    TC: O(N) where N is number of digits in number
    Space: O(10) ~ O(1) constant space

    Note: To understand why we are using last index, and not the first one. try considering this example [4,9,9] if we consider first index then max_no_obtained = [9,4,9] but with last index we get [9,9,4]

*/

class Solution {
public:
    int maximumSwap(int num) 
    {
        string s = to_string(num);
        
        vector<int> hash(10, -1);
        
        for(int i=0; i<s.length(); i++)
        {
            hash[s[i]-'0']=i;    
        }
        
        
        for(int i=0; i<s.length(); i++)
        {
            for(int j=9; j>s[i]-'0'; j--)   // j should be greater than current element, then only there is point to swap the element, otherwise if we swap then no. become smaller
            {
                if(hash[j]>i)   // and this number(j) should lie after the current(i) element, otherwise the number will become smaller than current number even.
                {
                    char temp=s[i];
                    s[i]=s[hash[j]];
                    s[hash[j]]=temp;
                    
                    return stoi(s);
                }
            }
        }
        
        return num;
        
    }
};