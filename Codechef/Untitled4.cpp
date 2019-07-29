
#include "bits/stdc++.h"
#define sync ios_base::sync_with_stdio(0)
#define ll unsigned long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vll vector<long long>
using namespace std;

int main() {
    sync;
    ll t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        ll answer = 0;
        int ones = count(all(s), '1');
        int zeros = count(all(s), '0');
        for(int i = 0; i < n-1; i++) {
            int t0 = 0, t1 = 0;
            if(s[i] == '1') {
                t1++;
            }
            else {
                t0++;
            }
            for(int j = i+1; j < n; j++) {
                if(s[j] == '1') {
                    t1++;
                    if(t1 * t1 > zeros) break;
                }
                else {
                    t0++;
                    if(ones * ones < t0) break;
                }
                if(t1 * t1 == t0) answer++;
            }
            if(s[i] == '1') ones--;
            else zeros--;
        }
        cout << answer << endl;
    }
    return 0;
}
