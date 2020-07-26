/*
 * problem:    https://www.codechef.com/APRIL20B/problems/COVIDLQ
 * solution : we need to find if the two 1s  have least gap of 5.
 *            Hence we calculate hte value of first occurence of 1 and
 *            then looking for all the ones after it. If another one 
 *            is found within a gap of less than 5, we break the loop. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        int c = n;
        for(int i = 0 ; i < n ; i++){
            if(a[i] == 1){
                c = i;
                break;
            }
        }
        int z = 0;
        bool x = true;
        for(int i = c + 1 ; i < n ; i++){
            if(a[i] == 0){
                z++;
            }
            else{
                if(z < 5 && z != n){
                    x = false;
                    break;
                }
                z = 0;
            }
        }
        if(x == false)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
