#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find b % a 
int Modulo(int a, char b[]) 
{ 
    // Initialize result 
    int mod = 0; 
  
    // calculating mod of b with a to make 
    // b like 0 <= b < a 
    for (int i = 0; i < strlen(b); i++) 
        mod = (mod * 10 + b[i] - '0') % a; 
  
    return mod; // return modulo 
} 
  
// function to find last digit of a^b 
int LastDigit(char a[], char b[]) 
{ 
    int len_a = strlen(a), len_b = strlen(b); 
  
    // if a and b both are 0 
    if (len_a == 1 && len_b == 1 && b[0] == '0' && a[0] == '0') 
        return 1; 
  
    // if exponent is 0 
    if (len_b == 1 && b[0] == '0') 
        return 1; 
  
    // if base is 0 
    if (len_a == 1 && a[0] == '0') 
        return 0; 
  
    // if exponent is divisible by 4 that means last digit will be pow(a, 4) % 10. 
    // if exponent is not divisible by 4 that means last digit will be pow(a, b%4) % 10 
    int exp = (Modulo(4, b) == 0) ? 4 : Modulo(4, b); 
  
    // Find last digit in 'a' and compute its exponent 
    int res = pow(a[len_a - 1] - '0', exp); 
  
    // Return last digit of result 
    return res % 10; 
} 
  
// Driver program to run test case 
int main() 
{ 
    char a[] = "117", b[] = "3"; 
    cout << LastDigit(a, b); 
    return 0; 
} 