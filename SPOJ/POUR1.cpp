  /*
   problem  : https://www.spoj.com/problems/POUR1/
  solution  : First we need to find the cases when the answer is -1.Oviously, it is the case when the c is greater than
              both a and b. It is clear that exactly c litres of water can be filled using a and b only if c can be written 
	      in the form of linear combination of a and b.
	      Then we find out the minimum answer using the pouring step shown below.
 */
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int pour (int A, int B, int C) {
  int move = 1, a = A, b = 0, tfr;
  while (a != C && b != C) {
    tfr = min(a, B - b);
    b += tfr;                                  // In the pouring step, we fill 'a', and empty it into 'b' until it is full.
    a -= tfr;                                  // When 'b' if full, it is emptied.This process is continued until one of the 
    move++;                                    // bottles contains 'c' litres of water.
    if (a == C || b == C)
      break;
    if (a == 0) {
      a = A;
      move++;                               
    }
    if (b == B) {
      b = 0;
      move++;
    }
  }
  return move;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int  a, b, c;
	    cin >> a >> b >> c;
	    if (c > a && c > b)
            cout << "-1" << endl;
        else if (c % __gcd(a, b) != 0)       // if c is not divisble by gcd(a,b) then it cant be expressed in
            cout << "-1" <<endl;            // the form of ax + by.(Using concepts of Diophanite equations)
        else
            cout << min(pour(a , b , c) , pour(b , a , c)) << endl;   // To find the minimum moves in pouring step of both bottles
	}
	return 0;
}
