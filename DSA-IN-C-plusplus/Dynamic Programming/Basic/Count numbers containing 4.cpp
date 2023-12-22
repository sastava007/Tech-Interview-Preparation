class Solution {
  public:
    int countNumberswith4(int N) {
        // code here
        int ans = 0;
        for(int i=4; i<=N; i++){
            int n = i;
            while(n > 0){
                int k=n%10;
                if(k==4){
                    ans++;
                    break;
                }
                
                n = n/10;
            }
        }
        
        return ans;
    }
};
