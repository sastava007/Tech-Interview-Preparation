/* As vectors are sparse, which means they contain a lot of zeroes and their is no point in multiplying the no by 0 becz the result is going to be zero. So we skip them
    an store the remaing in a hash table as {key, value} where key = index and value = actual value of element. We build hash table for bot the vectors and then multiply them

    O(N) time
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {

  // Dot product of two sparse vectors stored in hash tables
  unordered_map<int, double> asht({{0, 1.}, {7, 2.}, {8, 3.}});     // have to build yourself not provided in question
  unordered_map<int, double> bsht({{7, 4.}, {8, 9.}});             

  int idx_a;
  double val_a, val_b;
  double dot = 0;

  for (auto it : asht)  // iterate over the key(indexes and check if same index or key is present in other hash_table too, then multiply values of both of them. otherwise don't do anything ) 
  {
    idx_a = it.first;
    val_a = it.second;
    auto itb = bsht.find(idx_a);
    if (itb != bsht.end())
    {
      val_b = itb->second;
      dot += val_a * val_b;
    }
  }
  cout << dot; // 35

  return 0;
}