#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int max_of_four(int a, int b, int c, int d){
    if(a>b && a>c && a>d){
        return a;
    }
    else if(b>a && b>c && b>d){
        return b; 
    }
    else if(c>a && c>b && c>d){
        return c;
    }
    else {
        return d;
    }

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int ans = max_of_four(a, b, c, d);
    cout<<ans;
    
    return 0;   
    
}



