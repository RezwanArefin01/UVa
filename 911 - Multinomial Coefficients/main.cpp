#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m,z,j;
    while(cin>>n>>m) {
        int A[105], sum = 0;
        for(int i=1; i<=n; i++) A[i] = i;

        while(m--) {
            cin>>z; sum+=z;
            for(int i=2; i<=z; i++) {
                j = i;
                for(int k = 2; k<=n; k++) {
                    int g = __gcd(A[k], j);
                    A[k]/=g;
                    j/=g;
                }
            }
        }
        if(sum != n) puts("0");
        else {
            long long ret = 1;
            for(int i=1; i<=n;i++) ret*=A[i];
            cout<<ret<<endl;
        }
    }
}
