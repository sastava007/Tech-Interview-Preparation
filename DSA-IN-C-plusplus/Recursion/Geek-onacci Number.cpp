#include <iostream>
using namespace std;

int geekonaci(int a, int b, int c, int n){
    if(n==1) return a;
    if(n==2) return b;
    if(n==3) return c;
    
    
    int ans = geekonaci(a, b, c, n-1) + geekonaci(a, b, c, n-2) + geekonaci(a, b, c, n-3);
    return ans;
}


int main() {
	//code
	
	int t;
	cin>>t;
	
	while(t--){
	    int a, b, c, n;
	    cin>>a>>b>>c>>n;
	    
	    cout<<geekonaci(a, b, c, n)<<endl;
	}
	
	return 0;
}
