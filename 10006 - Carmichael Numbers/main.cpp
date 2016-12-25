#include<bits/stdc++.h>
using namespace std;
vector<int> chm = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973};
int main() {
    int n; while(cin>>n && n) {
        if(binary_search(chm.begin(), chm.end(), n)) cout<<"The number "<<n<<" is a Carmichael number."<<endl;
        else cout<<n<<" is normal."<<endl;
    }
}
