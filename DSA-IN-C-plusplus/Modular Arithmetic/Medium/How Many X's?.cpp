// User function Template for C++

class Solution {
  public:
    int countX(int L, int R, int X) {
        // code here
        int count = 0;
        for(int i=L+1; i<R; ++i){
            int num = i;
            while(num>0){
                if(num % 10 == X){
                    ++count;
                }
                
                num /= 10;
            }
        }
        
        return count;
    }
};
