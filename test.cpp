#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll ans = 0;
unordered_map<ll, vector<ll>> mp;
ll dfs(ll id)
{
  if (mp[id].size() == 0)
    return 0;
  vector<int> child;
  for (int i = 0; i < mp[id].size(); i++)
  {
    child.push_back(dfs(mp[id][i]));
  }
  for (int i : child)
  {
    if (i == 0)
    {
      ans++;
      return 1;
    }
  }
  for (int i : child)
  {
    if (i == 1)
      return 2;
  }
  return 0;
}
int main()
{
  ll n;
  cin >> n;
  for (ll i = 0; i < n - 1; i++)
  {
    ll x, y;
    cin >> x >> y;
    mp[x].push_back(y);
    mp[y].push_back(x);
  }
  cout << (dfs(1) < 1 ? 1 : 0) + ans;
}