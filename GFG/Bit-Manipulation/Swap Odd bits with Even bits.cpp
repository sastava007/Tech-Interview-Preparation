/*
    To get set bits at even position of a no take its (& AND) with 0xAAAAAAAA becz A=1010 which is 1 at every even position
    And to get set bits at odd position of a no take its (& AND) with 0x55555555 becz 5=0101 which is 1 at every odd position
    https://practice.geeksforgeeks.org/problems/swap-all-odd-and-even-bits/0
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int even_bits = n&(0xAAAAAAAA);
        int odd_bits = n&(0x55555555);

        // right shift all even set bits
        even_bits = even_bits>>1;
        // left shift all odd set bits
        odd_bits = odd_bits<<1;

        n = even_bits|odd_bits;
        cout<<n<<"\n";
    }
    
    return 0;
}