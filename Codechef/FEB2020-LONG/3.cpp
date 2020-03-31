/*
problem  : https://www.codechef.com/FEB20B/problems/CASH/
solution : We need to simply apply the brute force approach to solve this problem 
           since ther are only 4!(24) possible cases which arise.First we create a
	   4*4 array which contains the number of requests at a given time for a 
	   given movie.Then we check all possible cases and find the maximum 
	   profit among them. We do so by sorting the number of requests for a given 
	   case and setting maximum ticket price at the time when the nummber of requests 
	   are maximum.
*/
#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  
	ll T,total_profit=0;
	cin >> T;
	char m[4]={'A','B','C','D'};
	int t[4] = { 12 ,3 , 6 , 9 };
	while(T--){
	    ll n, b, i, j, max_profit= -10000, profit=0;
	    char a;
	    ll x[4][4] = {0};
	    cin >> n;
        while(n--){
            cin >> a;
            cin >> b;
            for(ll k = 0 ; k < 4 ; k++){
                if(m[k] == a)
                i = k;
                if (t[k] == b)
                j = k;
            }
            x[i][j]++;
        }
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ;j < 4; j++){
               if(j == i)
                  continue;
                for(int k = 0 ; k < 4; k++){
                    if(k == j || k == i)
                        continue;
                    for(int l = 0;l < 4; l++){
                        if(l == k || l == j || l == i)
                            continue;
                        int d[4]={ x[i][0], x[j][1], x[k][2], x[l][3]};   
                        sort(d,d + 4);
                          for(int m = 0; m < 4 ; m++){
                            if(d[m] == 0)
                                profit -= 100;
                            profit += d[m]*25*(m+1);
                          }
                        max_profit = max(profit,max_profit);
                        profit=0;
                    }
                }
            }
        }
        cout << max_profit << endl;
        total_profit += max_profit;
	}
	cout << total_profit << endl;
	return 0;
}
