#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
long long factorial[21] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
string getPermutation(const string& source, long long permutation) {
   string result(source);
   for(int i = 0; i < source.size(); ++i) {
      sort(result.begin() + i, result.end());
      if (permutation == 0) break;
      int charPos = i + permutation / factorial[source.size() - i - 1];
      swap(result[i], result[charPos]);
      permutation = permutation % factorial[source.size() - i - 1];
   }
   return result;
}
int main() {
   int n; cin >> n;
   while(n--) {
      string source;
      long long permutation;
      cin >> source >> permutation;
      cout << getPermutation(source, permutation) << '\n';
   }
}
