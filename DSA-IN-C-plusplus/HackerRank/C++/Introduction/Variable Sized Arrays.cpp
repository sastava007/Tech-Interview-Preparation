#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;
    int index,value,col,size;
    vector<vector<int>>n_vector;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        vector<int>i_vector;
        cin>>size;
    
    for(int j=0;j<size;++j){
        cin>>value;
        i_vector.push_back(value);
    }
    
    n_vector.push_back(i_vector);
    
    
}

for(int k=0;k<q;++k){
    cin>>col>>index;
    cout<<n_vector[col][index]<<endl;
} 

 

    return 0;
}
