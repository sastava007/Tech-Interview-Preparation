/* 
    Given a string, sort it in decreasing order based on the frequency of characters. And the same characters must be together.
    "tree" => "eert"
    "loveleetcode" => "eeeeoollvtdc"
*/

/* TC & Space: O(N) */

string frequencySort(string s)
{
    unordered_map<char, int> m; // instead we can use array[128] = {0}
    for (char c : s)
        m[c]++;

    vector<pair<char, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) -> bool {
        return a.second > b.second;
    });

    string result = "";
    for (auto it : v)
    {
        string temp = string(it.second, it.first);
        result += temp;
    }
    return result;
}

/* TC : O(nlogn) */

string frequencySort(string s)
{
    unordered_map<char, int> m;
    for (char c : s)
        m[c]++;

    sort(s.begin(), s.end(), [&](char a, char b) {
        return m[a] > m[b] || (m[a] == m[b] && a < b);  // If frequency of two characters is same then sort in ascending order
    });

    return s;
}