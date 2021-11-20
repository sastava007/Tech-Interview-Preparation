#include<iostream>
#include<math.h>
using namespace std;
/*This code is contributed by Sajal193. This is a basic level code that gives a 
newbie a basic idea of implementation of nested loops and flow commands. ENJOY */
int main(){
    int t;
    cin>>t;//for test cases
    while(t--)
    {
        int m,n; //initializing two variables
        cin>>m>>n;bool r; // using bool so as to check condition whether the second
        //(nested) loop is executed or not.
   
        for (int i =m; i<=n; i++)
        {
            if (i == 1 || i ==0) // if i equals 1 then skip to next increment
            {
                continue;
            }
            r = true;
            for (int j =2; j<=sqrt(i); j++)//condition loop for checking prime number
            { if (i%j == 0)
               { r = false;
                   break;
               }
            }
            
            if ( r == true) // To check whether nested loop is traversed or not
            {
                cout<<i<<endl;
            }

        }
    }
    return 0;
}