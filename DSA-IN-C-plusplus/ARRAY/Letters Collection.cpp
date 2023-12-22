class Solution{
public:

    bool issafe(int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>= n || j>=m){
            return false;
        }
        return true;
    }

    int query2(int a,int b,vector<vector<int>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        
        int su = -mat[a][b];
        for(int i = a-2 ; i<=a+2;i++){
            for(int j = b-2; j <= b+2 ;j++){
                if(issafe(i,j,n,m)){
                    su += mat[i][j];
                }
            }
        }
        
        su -= query1(a,b,mat);
        
        return su;
    }

    int query1(int a,int b,vector<vector<int>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        
        int su = -mat[a][b];
        for(int i = a-1 ; i<=a+1;i++){
            for(int j = b-1; j <= b+1 ;j++){
                if(issafe(i,j,n,m)){
                    su += mat[i][j];
                }
            }
        }
        
        return su;
    }
    
    

    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        vector<int> ans;
        
        for(int i = 0; i <q ; i++){
            if(queries[i][0]==1){
                ans.push_back(query1(queries[i][1],queries[i][2],mat));
            }else{
                ans.push_back(query2(queries[i][1],queries[i][2],mat));
            }
        }
        
        return ans;
    }
};
