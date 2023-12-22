class Solution {
public:
    int romanToDecimal(string &s) {
        unordered_map<char, int> romanToInt = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        int prev = 0;  

        for (int i = s.length() - 1; i >= 0; i--) {
            int current = romanToInt[s[i]];
            
            if (current < prev) {
                result -= current;  // If the current value is less than the previous, subtract it.
            } else {
                result += current;  // Otherwise, add it to the result.
            }
            
            prev = current;
        }

        return result;
    }
};
