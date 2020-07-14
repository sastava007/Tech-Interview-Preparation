/*  Roman numerals are usually written largest to smallest from left to right.
    
    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

*/

public static String intToRoman(int num)
{
	if (num < 1 || num > 3999) return "";
	
	StringBuilder result = new StringBuilder();
	
	String[] roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int[] values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	
	int i = 0;
            //iterate until the number becomes zero, NO NEED to go until the last element in roman array
	while (num >0) {
		while ( num >= values[i]) {
			num -= values[i];
			result.append(roman[i]);
		}
		i++;
	}
	return result.toString();
}