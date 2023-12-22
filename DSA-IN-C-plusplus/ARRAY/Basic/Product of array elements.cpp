//User function Template for C++



/*  
     ar[] is the array
     n = number of element in array
     mod = modulo value;
*/
long long int product(int ar[], int n, long long int mod)
 {
     
     //code here
     long long result = 1;
     
     for(int i = 0; i<n; i++){
         
         result *= (ar[i] % mod);
         
         if(result >= mod){
             result %= mod;
         }
     }
         
     return result;
  
     
 }
