#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,k; cin>>t;
    while (t--){
        cin>>k; if(k < 0) k = -k;
        int n = 0, sum = 0;
        while (sum < k) sum += (++n);
        if (k & 1) while (sum % 2 != 1) sum += (++n);
        else while (sum % 2 != 0) sum += (++n);
        if (!k) cout<<"3\n";
        else cout<<n<<endl;
        if (t) puts("");
    }
}
