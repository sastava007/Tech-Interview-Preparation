#include<bits/stdc++.h>
using namespace std;

int makeEqual(string &str1, string &str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2)
	{
		for (int i = 0 ; i < len2 - len1 ; i++)
			str1 = '0' + str1;
		return len2;
	}
	else if (len1 > len2)
	{
		for (int i = 0 ; i < len1 - len2 ; i++)
			str2 = '0' + str2;
        return len1;
	}
}

string addStrings( string first, string second )
{
	string result;

	int length = makeEqual(first, second);
	int carry = 0;

	for (int i = length-1 ; i >= 0 ; i--)
	{
		int bit1 = first.at(i) - '0';
		int bit2 = second.at(i) - '0';
		int sum = (bit1 ^ bit2 ^ carry)+'0';
		result = (char)sum + result;
		carry = (bit1&bit2) | (bit2&carry) | (bit1&carry);
	}
	if (carry) result = '1' + result;
	return result;
}

int multiplyiSingle(string a, string b)
{ return (a[0] - '0')*(b[0] - '0'); }

long int multiply(string X, string Y)
{
	int n = makeEqual(X, Y);
	if (n == 0) return 0;
	if (n == 1) return multiplyiSingle(X, Y);
	int n1 = n/2;
	int n2 = (n-n1);
	string Xl = X.substr(0, n1);
	string Xr = X.substr(n1, n2);
	string Yl = Y.substr(0, n1);
	string Yr = Y.substr(n1, n2);
	long int P1 = multiply(Xl, Yl);
	long int P2 = multiply(Xr, Yr);
	long int P3 = multiply(addStrings(Xl, Xr), addStrings(Yl, Yr));
	return P1*(1<<n) + (P3 - P1 - P2)*(1<<n2) + P2;
}

main()
{
    string a,b;
    cout<<"Input first String: ";
    cin>>a;
    cout<<"Input second string: ";
    cin>>b;
    cout<<"Product: "<<multiply(a,b);
}
