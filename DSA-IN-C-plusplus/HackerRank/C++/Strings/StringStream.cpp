#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    vector <int> toReturn;
    stringstream ss(str);

    char ch;
    int a;
    ss >> a;

    toReturn.push_back(a);
    for(int i=0;i < str.size();i++){
         ss >> ch >> a;
         if(ss.fail()){
             break;
         } else{
         toReturn.push_back(a);
     }
    }

	return toReturn;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
