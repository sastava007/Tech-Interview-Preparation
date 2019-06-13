#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, i, c = 0, pos1, pos2,min_ele;
    cin >> n >> k;
    map<int,int> mp;
    int arr[n];
    for (i = 1; i <= n; i++) {
      pos1 = k + i;
      pos2 = -k + i;

      if (pos1 >= 1 && pos1 <= n && pos2 >= 1 && pos2 <= n)
      {
        min_ele = min(pos1, pos2);
        if (mp.find(min_ele)==mp.end())
         {
              mp.insert({min(pos1, pos2),min(pos1, pos2)});
              arr[i-1]=min(pos1, pos2);
              c++;
         }
        else
          {
              mp.insert({max(pos1, pos2),max(pos1, pos2)});
              arr[i-1]=max(pos1, pos2);
              c++;
          }
      }
      else if (pos1 >= 1 && pos1 <= n && mp.find(pos1) == mp.end())
        {
            mp.insert({pos1,pos1});
            arr[i-1]=pos1;
            c++;
        }

       else if (pos2 >= 1 && pos2 <= n && mp.find(pos2) == mp.end())
        {
          mp.insert({pos2,pos2});
          c++;
          arr[i-1]=pos2;
        }
    }
    if (c == n) {

      cout<<"YES";
      cout << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}

