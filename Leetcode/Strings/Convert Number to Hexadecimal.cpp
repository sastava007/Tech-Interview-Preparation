/* 
    The no. data type is not unsigned int. Without the condition count++ < 8, it will trap into infinite loop when the input is negative like -1 (0xffff ffff). 
    Actually, the count is used to handle negative numbers. You can test it by inputting -1, if no count, the while loop is infinite, since -1 >> 4 is till -1. the count is used to avoid infinite loop.
*/

const string HEX = "0123456789abcdef";
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string result;
        int count = 0;
        while (num && count++ < 8) {
            result = HEX[(num & 0xf)] + result;
            num >>= 4;
        }
        return result;
    }
};