

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        
        // code here
        int dist1 = -1;
        int dist2 = -1;
        
        int res = INT_MAX;
        for(int i = 0; i<n; i++){
            if(a[i] == x){
                dist1 = i;
                
            }
            
            if(a[i] == y){
                dist2 = i;
            }
            
            if(dist1 != -1 && dist2 !=-1){
                res = min(res, abs(dist1 - dist2));
            }
        }
        
        return (dist1 == -1 || dist2 == -1) ? -1 : res;
    }
};
