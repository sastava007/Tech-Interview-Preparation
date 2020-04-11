/*
    https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
    https://youtu.be/fZ3p2Iw-O2I
*/

// Solved using 0 based indexing, so add 1 while printing answer
#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
   if(n==1)
    return 0;
   else
   return ((josephus(n-1,k)+k)%n);
}
int main() 
{	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<josephus(n,k)+1<<"\n";	
	}
	return 0;
}

// Solved considering 1 based indexing
int josephus(int n, int k)
{
   if(n==1)
    return 1;
   else
   return ((josephus(n-1,k)+k-1)%n+1);
}
