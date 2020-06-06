/* Idea is to simulate how we read the numbers, i.e we can group three digits at a time and then we can call some helper method to process that number <1000 to chunk of words
TC: O(K) where K is the number of digits and Space Complexity will be O(1)

*/

class Solution {
public:
    vector<string> lessThanTwenty{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    vector<string> thousands{"", "Thousand", "Million", "Billion"};
        
        
    string numberToWords(int num) 
    {
       if(num==0)
           return "Zero";
        
        int index=0;
        string result;
        
        while(num > 0)
        {
            if(num % 1000 != 0)
            {
                string temp;
                helper(temp, num%1000);
                
                result = (temp + thousands[index] + " ") + result;
            }
            index++;
            num /= 1000;
        }
        
        //trim the white spaces
        while(*result.begin()==' ')
            result.erase(0, 1);
        while(*(result.end()-1)==' ')
            result.pop_back();
        
        return result;
    }
    
private:
    
    void helper(string &temp, int num)
    {
        if(num==0)
            return;
        else if(num<20)
        {
            temp += lessThanTwenty[num] + " ";
            return;
        }
        else if(num<100)
        {
            temp += tens[num/10]+ " ";
            helper(temp, num%10);
        }
        else
        {
            temp += lessThanTwenty[num/100] + " Hundred ";
            helper(temp, num%100);
        }
    }
};