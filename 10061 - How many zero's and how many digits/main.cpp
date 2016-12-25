#include<bits/stdc++.h>
using namespace std;

long zer(int n, int base) {
    long zero = INT_MAX;
    for(long i = 2; i<= base; i++) {
        if(base % i != 0) continue;
        long int_b = 0, int_n = 0;
        while(base % i == 0 && base != 0) {int_b ++, base /= i;}
        for(long j = i; j<=n; j*=i) int_n += n/j;
        if(zero > int_n / int_b) zero = int_n / int_b;
    } return zero;
}
long dig(int n, int b) {
    double sum = 0.0, base = log(double(b));
    for(int i=2; i<=n;i++) sum += log(i);
    return long((sum/base + 1e-4 )+ 1);
}
int main() {
    int n,b; while(cin>>n>>b) {
        cout<<zer(n,b)<<" " <<dig(n,b)<<endl;
    }
}
