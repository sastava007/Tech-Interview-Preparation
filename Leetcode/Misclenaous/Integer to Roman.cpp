/*  Roman numerals are usually written largest to smallest from left to right.
    
    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

*/

class Solution {
public:
    string intToRoman(int num) 
    {
        string dict[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> val ={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            
        int i=0;
        string res;
                         
        while(num>0)	// Iterate until the number becomes zero, NO NEED to go until the last element in roman array
        {
            while(num>=val[i])
            {
                num -= val[i];
                res += dict[i];
            }
            i++;
        }
        return res;
    }
};

/* Roman to integer */	
int romanToInt(string s) 
{
	unordered_map<char, int> m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	
	int i = s.length()-1, prev = 0, ans=0;
	while(i>=0)
	{
		int curr = m[s[i]];
		if(curr >= prev)
			ans += curr;
		else
			ans -= curr;
		prev = curr;
		i--;
	}
	return ans;
}