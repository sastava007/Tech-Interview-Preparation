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

/* Without maintaining extra array O(1) space */
string multiply(string num1, string num2) 
{
    int sz1=num1.size(),sz2=num2.size();
    if (sz1==0 || sz2==0) return "";

    string res(sz1+sz2,'0');  // the result can be at most sz1+sz2 digits

    for (int i=sz2-1;i>=0;i--)
    {
        int start=sz1+i;
        int carry=0,sum=0;
        for (int j=sz1-1;j>=0;j--)
        {
            sum = (num1[j]-'0')*(num2[i]-'0')+res[start-sz1+1+j]-'0'+carry;
            carry = sum/10;
            sum = sum%10;
            res[start-sz1+1+j] = sum+'0';
        }
        if (carry)
        {
            sum = carry+res[start-sz1]-'0';
            carry = sum/10;
            sum = sum%10;
            res[start-sz1] = sum+'0';
        }
    }
    int i=0;
    while (i<sz1+sz2-1)     // we aren't iterating till last element, becz there can be a single 0 in our result too
    {  
        if (res[i]=='0') i++;
        else break;
    }
    return res.substr(i);
}