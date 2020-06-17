/*  Idea is to first divide the num/den simply and then check whether some remainder(num%den) exists or not, if doesn't then simply return the string built so far. Else add a decimal 
    and store the current numerator in a hash table, next time when doing the same multiply the numerator by 10 as it is already <0 and check whether we have already seen this numerator before or not
    if yes then simply add () and return result. Else keep on doing the same.

    TC: O(N) & Space: O(N) where N is the number of unique remainders.

    PS: We can make use of Floyd's Cycle Detection algorithm, for finding TC: O(N) and space complexity in O(1)
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        if(numerator==0)
            return to_string(0);
        
        string result = "";
        bool isNegative = (numerator<0) ^ (denominator<0);
        if(isNegative)
            result += '-';
        
        long num = abs(numerator);
        long den = abs(denominator);
        
        result += to_string(num/den);
        num %= den;
        if(num==0)  // if the numerator was perfectly divisible
            return result;
        
        result += '.';
        
        unordered_map<long, int> hash;
        hash[num]=result.length();
        
        while(num!=0)
        {
            num *= 10;
            result += to_string(num/den);
            num %= den;
            
            if(hash.find(num) != hash.end())
            {
                result.insert(hash[num], "(");
                result += ")";
                break;
            }
            else
                hash[num] = result.length();
        }
        
        return result;
    }
};