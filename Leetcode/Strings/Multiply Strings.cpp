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
                result[i+j+1] = sum%10;     // first digit will get placed at n+m-1
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

/* Without maintaining extra array O(1) space, other than ofcourse that required for output string */

string multiply(string num1, string num2) 
{
    if(num1=="0" || num2=="0")
        return "0";
    
    if(num1=="1")
        return num2;
    else if(num2=="1")
        return num1;
    
    string result(num1.size()+num2.size(), '0');
    for(int i=num1.size()-1; i>=0; i--)
    {
        for(int j=num2.size()-1; j>=0; j--)
        {
            int sum = (num1[i]-'0')*(num2[j]-'0') + (result[i+j+1]-'0');
            result[i+j+1] = sum%10+'0';
            result[i+j] += sum/10;
        }
    }
    
    for(int i=0; i<result.size(); i++)
    {
        if(result[i] != '0')   // to skip all the leading zeroes
            return result.substr(i);
    }
    
    return "0";     // this means that there were all leading zeroes     
}