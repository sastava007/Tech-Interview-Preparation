#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
#define pb push_back
#define ll long long int
using namespace std;

int dayofweek(ll d, ll m, ll y)  
{  
    static ll t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  
    y -= m<3;  
    return (y+y/4-y/100+y/400+t[m-1]+d)%7;  
}  
bool checkYear(ll year)  
{  
    if (year % 400 == 0)  
        return true;  
    if (year % 100 == 0)  
        return false;  
    if (year % 4 == 0)  
        return true;  
    return false;  
}  
int main() {
	int t;
	cin>>t;
	while(t--){
	    ll m1,m2,k=0;
	    ll y1,y2,x=0;
	    cin>>m1>>y1;
	    cin>>m2>>y2;
	    if(m2<2)
	    y2-=1;
	    if(m1>2)
	    y1+=1;
	    if(y2-y1+1 <=400){
	       for(int i=y1;i<=y2;i++){
	           if(checkYear(i)==true && dayofweek(1,2,i)==6)
	           x++;
	           else if(checkYear(i)==false && (dayofweek(1,2,i)==6 || dayofweek(1,2,i)==0))
	           x++;
	       }
	    }
	    else{
	        if(y1%400==0){
	            if(checkYear(y1)==true && dayofweek(1,2,y1)==6)
	           x++;
	           else if(checkYear(y1)==false && (dayofweek(1,2,y1)==6 || dayofweek(1,2,y1)==0))
	           x++;
	        }
	       for(int i=y1%400;i<=400;i++){
	           if(i==0)
	           continue;
	           if(checkYear(i)==true && dayofweek(1,2,i)==6)
	           x++;
	           else if(checkYear(i)==false && (dayofweek(1,2,i)==6 || dayofweek(1,2,i)==0))
	           x++;
	       }
	        for(int i=1;i<=400;i++){
	           if(checkYear(i)==true && dayofweek(1,2,i)==6)
	           k++;
	           else if(checkYear(i)==false && (dayofweek(1,2,i)==6 || dayofweek(1,2,i)==0))
	           k++;
	       }

	       k*=(y2/400)-(y1/400)-1;
	       x+=k;
	       for(int i=1;i<=y2%400;i++){
	           if(checkYear(i)==true && dayofweek(1,2,i)==6)
	           x++;
	           else if(checkYear(i)==false && (dayofweek(1,2,i)==6 || dayofweek(1,2,i)==0))
	           x++;
	       }
	    }
	       cout << x << endl;
	}
	return 0;
}
