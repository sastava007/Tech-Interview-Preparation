/* Similar to Add Binary Problem */

class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        if(num1[0]!='-' && num2[0]!='-')
            return add(num1, num2);
        else if(num1[0]=='-' && num2[0]=='-')
            return "-"+add(num1.substr(1), num2.substr(1));
        else if(num1[0]=='-')   //we're considering num1>0, so in such case swap
            swap(num1, num2);
        
        num2 = num2.substr(1);

        int comp = compare(num1, num2);

        if(comp==0)
            return "0";
        else if(comp<0)
            return "-"+subtract(num2, num1);
        else
            return subtract(num1, num2);
    }

private:
    string add(string num1, string num2)
    {
        int i=num1.length()-1, j=num2.length()-1, carry=0;
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

    string subtract(string num1, string num2)
    {
        int i=num1.length()-1, j=num2.length()-1, carry=0;
        string res;
        
        while(i>=0 || j>=0 || carry)
        {
            int a=0,b=0;
            if(i>=0)
                a=num1[i--]-'0';
            if(j>=0)
                b=num2[j--]-'0';

            int sub = a-b-carry;
            int temp = sub<0? 10+sub : sub;
            res = static_cast<char>(temp+'0') + res;
            carry = sub<0?1:0;
        }
        while(!res.empty() && *(res.begin())=='0')      // remove the leading zeroes, consider the case 10 - 5 => 05 
          res.erase(res.begin());
        return res;
    }

    int compare(string num1, string num2)
    {
        int l1 = num1.length(), l2 = num2.length();
        if(l1<l2)
            return -1;
        else if(l1>l2)
            return 1;
        else
        {
            if(l1==0)
                return 0;
            else if(num1[0]<num2[0])
                return -1;
            else if(num1[0]>num2[0])
                return 1;
            else
            {
                return compare(num1.substr(1), num2.substr(1));
            }
        }
    }
};

/* Follow Up: Decimals */

string add(string num1, string num2)
{
	int d1 = num1.find('.'), d2 = num2.find('.');
	int right = max(num1.length()-d1, num2.length()-d2);    // to find the num
	
	int i = right-1, carry=0;
	string res;
	
	while(i+d1>=0 || i+d2>=0)
	{
		if(i==0)	//when we reach the point of decimal
		{
			res = "." + res;
			i--;
			continue;
		}
		
		int sum;
		if(i+d1>=0 && i+d1<num1.length())
			sum = num1[i+d1]-'0';
			
		if(i+d2>=0 && i+d2<num2.length())
			sum += num2[i+d2]-'0';
		
		sum += carry;
		res = to_string(sum%10) + res;
		carry = sum/10;
		i--;
	}
	if(carry != 0)
		res = "1" + res;
	return res;
}