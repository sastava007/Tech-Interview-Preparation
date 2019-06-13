#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,i;
	cin>>n;
	int size=2*n;
	int a[size];
	for(i=0;i<size;i++)
	cin>>a[i];
	sort(a,a+size);
	cout<<a[n-1];
	return 0;
}
