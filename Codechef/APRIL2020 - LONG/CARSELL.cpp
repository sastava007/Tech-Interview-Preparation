/*
problem : https://www.codechef.com/APRIL20B/problems/CARSELL
solution : It is a simple implemation problem in which to maximize the profit,
	   we need to sell the car which has maximum cost.Hence we first sort the
	   array and then sell cars accordingly
 */
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
#define mod 1000000007 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        for(int i = 0 ; i < n ; i++){
                cin >> a[i];
        }
        sort(a , a + n);
        ll profit = 0;
        for(int i = 0 ; i < n ; i++){
            profit = (profit % mod + max((ll)0 , (a[n-1-i] - i) % mod) ) % mod;
             //cout << profit << endl;
        }
        cout << profit << endl;
    }
    return 0;
}
