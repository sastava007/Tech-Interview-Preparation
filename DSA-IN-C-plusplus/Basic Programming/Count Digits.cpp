#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Declare variables to store count of vowels
    int a0 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0, a9 = 0;

    string s;
    cin >> s;
    int s_len = s.length();
    for(int i=0; i<s_len; i++) {

        if(s[i] == '0') {
            a0++;
        } 
		
		else if(s[i] == '1') {
            a1++;
        } 
		
		else if(s[i] == '2') {
            a2++;
        } 
		else if(s[i] == '3') {
            a3++;
        } 
		
		else if(s[i] == '4') {
            a4++;
        }

		else if(s[i] == '5') {
            a5++;
        }

		else if(s[i] == '6') {
            a6++;
        }

		else if(s[i] == '7') {
            a7++;
        }

		else if(s[i] == '8') {
            a8++;
        } else{
            a9++;
        }
    }
    // Print out the result to STDOUT
    cout << "0 " << a0 << endl;
	  cout << "1 " << a1 << endl;
    cout << "2 " << a2 << endl;
    cout << "3 " << a3 << endl;
    cout << "4 " << a4 << endl;
    cout << "5 " << a5 << endl;
	  cout << "6 " << a6 << endl;
	  cout << "7 " << a7 << endl;
	  cout << "8 " << a8 << endl;
	  cout << "9 " << a9 << endl;
    return 0;
}
