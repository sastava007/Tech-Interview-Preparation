/*  */

vector<int> plusOne(vector<int>& digits) 
{
    vector<int> res;
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) 
    {
        int sum = carry + digits[i];
        carry = sum / 10;
        res.push_back(sum % 10);
    }
    if (carry) res.push_back(1);
    reverse(res.begin(), res.end());
    return res;
}