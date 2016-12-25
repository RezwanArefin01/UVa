#include<bits/stdc++.h>
using namespace std;

int main() {
    int t,k; scanf("%d", &t); while(t--) {
        scanf("%*d %d", &k); cout<<(k^(k>>1))<<endl;
    }
}
