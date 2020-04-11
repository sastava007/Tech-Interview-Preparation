/*
    https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1
    Smart approach using prefix and suffix arrays
    The function returns a vector containing the increasing sub-sequence of length 3 if present else returns an empty vector
*/


vector<int> find3Numbers(vector<int> arr, int N)
{

    vector<int> ans;
    if (N < 3)
        return ans;

    int i, smaller[N], greater[N];
    smaller[0] = arr[0];
    greater[N - 1] = arr[N - 1];

    for (i = 1; i < N; i++)
        smaller[i] = min(arr[i], smaller[i - 1]);
    for (i = N - 2; i >= 0; i--)
        greater[i] = max(arr[i], greater[i + 1]);

    for (i = 1; i < N - 1; i++)
        if (arr[i] > smaller[i - 1] && arr[i] < greater[i + 1])
        {
            ans.emplace_back(smaller[i - 1]);
            ans.emplace_back(arr[i]);
            ans.emplace_back(greater[i + 1]);
            return ans;
        }
    return ans;
}