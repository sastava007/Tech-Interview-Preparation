/*
 * problem : https://www.codechef.com/APRIL20B/problems/STRNO
 *solution : Using concepts of Number theory, if n can be expressed as a product
             of more than or equal to k elements other than 1, the answer
	     is 1 otherwise 0.
 *
*/#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
#define numb 1000000000
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >>t;
    while(t--){
       ll x, k;
       cin >> x >> k;
       ll count = 0;
       bool v = true;
       for(ll i = 2 ; i*i < x ; i++){
            if(x % i == 0){
                v = false;
                break;
            }
       }
       while (x % 2 == 0){ 
            count++; 
            x /= 2; 
        } 
       // cout << count <<" " << x <<endl;
        for (ll i=3; i*i <= x ; i += 2){ 
            while (x % i == 0){ 
                x /= i;
                count++;
            } 
        }
        bool l = true;
       for(ll i = 2 ; i*i < x ; i++){
            if(x % i == 0){
                l = false;
                break;
            }
       }
       if(l == true)
            count++;
        //cout << count << endl;
       if(count >= k || (v == true && k==1))
            cout << "1" << endl;
       else
            cout << "0" <<endl;
    }
    return 0;
}
