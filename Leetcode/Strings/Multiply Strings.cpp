/* O(m*n) TC and O(m+n) space*/

class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if(num1=="0" || num2=="0")
            return "0";
        if(num1=="1")
            return num2;
        if(num2=="1")
            return num1;
        
        int n=num1.length(), m=num2.length();
        vector<int> result(n+m, 0);
        
        for(int i=n-1; i>=0; i--)
            for(int j=m-1; j>=0; j--)
            {
                int sum=(num1[i]-'0')*(num2[j]-'0')+result[i+j+1];
                result[i+j+1] = sum%10;
                result[i+j] += sum/10;
            }
        
        string res;
        
        for(int it: result)
        {
            if(it==0 && res.empty())    //remove the leading zeroes
                continue;
            
            res+=to_string(it);
        }
        
        return res;
        
    }
};