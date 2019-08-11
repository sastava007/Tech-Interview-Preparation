#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v{-4,-5},t{3};
    vector<int> ans(3);
    merge(v.begin(),v.end(),t.begin(),t.end(),ans.begin());
    for(auto it:ans)
        cout<<it<<" ";


}
