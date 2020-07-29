/*
 * https://www.codechef.com/APRIL20B/problems/UNITGCD
 * solution : to read n pages, at least n/2 days are required as no two
 *            even integers are coprime.Secondly,two consecutive integers
 *            are  always coprime . These two observations solve the problem
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1){
           cout << "1 \n1 1" << "\n"; 
        }
        else if(n%2 == 1){
            cout << n/2 << endl;
            cout <<"3 1 2 3"<<endl;
            for(int i = 4 ; i <= n ; i+=2){
                cout <<"2 " << i <<" " << i+1 << "\n";
            }
        }
        else{
            cout << n/2 << endl;
            cout << "2 1 2" << endl;
            for(int i = 3; i <= n ; i+=2){
                cout <<"2 " << i <<" " << i+1 << "\n";
            }
        }
    }
    return 0;
}
