// User function Template for C++

class Solution{
public:
    vector<int>v;
    vector<int> pattern(int N){
        // code here
        v.push_back(N);
        if(N <= 0){
            return v;
        }
        
        pattern(N-5);
        v.push_back(N);
        return v;
        
    }
};
