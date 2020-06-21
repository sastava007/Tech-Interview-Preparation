/* Single Number 2: In an array of integers, all no. occurs 3 times except one number which ocurrs 1 times. Find that number, without using any extra space */

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans = 0;
        for(int i=0; i<32; i++) 
        {
            int sum = 0;
            for(int num: nums)
                if((num>>i & 1) ==1)    // check if ith digit of every no is set or not. If set then increment the counter, and later % by 3 to get the remaining set bits
                    sum++;
            sum %= 3;
            ans |= (sum<<i);
        }
        
        return ans;
    }
};

/*  Single Number 3: All the numbers occurs twice except 2 numbers which occurs exactly once
    So idea is to first perform xor of all the numbers, this way we end up with xor of required two numbers. And, this xore will be non zero, becz these numbers are distinct so they'll be having
    atleast one set bit. 

    Now, what we can do it to find the first set bit number and using that grp. the entire array into 2 parts the first one that does not have a set bit at that position and other one that has
    a set bit a that position. Our required numbers will also get divided in these two sets. Now just xor individual elements of these set and we'll end with two numbers.

 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int xore = 0;
        for(int num: nums)    
            xore ^= num;    // we end up with xor of required 2 numbers
        
        vector<int> result = {0,0};
        
        xore &= -xore;  // find the first set bit number
        
        for(int num: nums)
        {
            if((xore&num) ==0)          // first grp: that doesn't have a set bit at that position
                result[0] ^= num;
            else
                result[1] ^= num;       // second grp: that doesn have a set bit at that position
        }
        
        return result;
    }
};