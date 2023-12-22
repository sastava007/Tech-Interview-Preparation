#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string arr[9]= {"one","two","three","four","five","six","seven","eight","nine"};
    int x,y;
    cin >> x >> y;
    for ( int i=x;i<=y;i++){
       if(i>=1&&i<=9){
           cout << arr[i-1] << endl;
       }
       else if(i%2==0){
           cout << "even" << endl;
       }
       else{
           cout << "odd" << endl;
       }
   }
   
    return 0;
     
}

