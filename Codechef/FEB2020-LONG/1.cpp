/*
problem : https://www.codechef.com/FEB20B/problems/SNUG_FIT
solution: the diameter of the circle inscribed in a rectangle is minimum of its length and breadth.
          pair the small elements with the small elements, middle elements with the middle elements,
	  and the big elements with the big elements, in order to maximize the final sum. 
*/
#include <iostream>
#include <algorithm>
#define ll long long int 
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
        int n;
        cin >> n;
        ll a[n], b[n], s=0;
        for(int i = 0 ;i < n ;i++)
            cin >> a[i];
        for(int i = 0 ;i < n ; i++)
            cin >> b[i];
            
        sort(a,a+n);
        sort(b,b+n);
        for(int i = 0; i < n; i++)
           s += min(a[i],b[i]);
        cout << s << endl;
    }
	return 0;
}
