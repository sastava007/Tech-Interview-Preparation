class Solution {
  public:
    int findPosition(int N) {
        // code here
        if(N==0) return -1;
        
        int count = 0, pos=0;
        while(N){
            if(N&1){
                count++;
            }
            
            pos++;
            N=N>>1;
        }
        
        return count==1 ? pos: -1;
    }
};
