/* 
	Approach Used: Bottom-up Dynamic Programming

	F(N) = F(N-1) + F(N-2) + F(N-3), so using the fact that we only need last three values, we can build up the solution taking first 3 values of F(0) = 0, F(1) = 1, F(2) = 1, and build the solution upto N using previous three values.

	Time Complexity: O(n)
	Space Complexity: O(1)

 */

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)return 0;
        int first = 0, second = 1, third = 1;
        for(int i=3; i <= n; i++){
            int fourth = first + second + third;
            first = second;
            second = third;
            third = fourth;
        }
        
        return third;
    }
};