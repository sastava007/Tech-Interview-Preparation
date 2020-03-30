#include <iostream>
#define ll long long int
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
	    ll n, k, s = 0, i;
	    cin >> n >> k;
	    ll a[n];
	    for(i = 0 ; i < n ;i++){
	         cin >> a[i];
	         s += a[i];
	    }
	   cout << (s % k) << endl;
	}
	return 0;
}
