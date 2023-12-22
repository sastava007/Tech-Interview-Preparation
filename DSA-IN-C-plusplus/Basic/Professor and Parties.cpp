

class Solution{
    public:
    
    string PartyType(long long int a[], int n)
    {
        // Your code goes here
        unordered_set<long long> h(a, a+n);
        return h.size() == n ? "GIRLS" : "BOYS";
    }
};
