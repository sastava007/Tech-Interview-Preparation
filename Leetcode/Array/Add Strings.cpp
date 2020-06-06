/* Similar to Add Binary Problem */

class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int i=num1.length()-1, j=num2.length()-1;
        
        int carry=0;
        
        string res;
        
        while(i>=0 || j>=0 || carry)
        {
            int a=0,b=0;
            if(i>=0)
                a=num1[i--]-'0';
            if(j>=0)
                b=num2[j--]-'0';
            
            int sum = a+b+carry;
            int temp = sum<10? sum : (sum-10);
            
            res = static_cast<char>(temp+'0') + res;
            carry = sum<10?0:1;
            
        }
        
        return res;
    }
};