#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define maxN 46342
bitset<maxN> isP;
vector<int> prime;
void sieve() {
    isP.set();
    isP.reset(0); isP.reset(1);
    for (int i = 4; i < maxN; i += 2)
        isP.reset(i);
    for (int i = 3; i * i < maxN; i += 2)
        if (isP[i])
            for (int j = i * i; j < maxN; j += i + i)
                isP.reset(j);
    prime.pb(2);
    for (int i = 3; i < maxN; i += 2)
        if (isP[i]) prime.pb(i);
}
long long LCMsum(int n) {
    if (n == 1) return 2;
    if ( n < maxN && isP[n]) return n+1;
    long long sum = 0 , cnt = 0, p = 0;
    while(p < prime.size() && n !=1) {
        long long tmp = 1;
        if(!(n%prime[p])) {
            while( !(n%prime[p])) {
                tmp *= prime[p], n /= prime[p];
            }
            sum += tmp;
            cnt++;
        } p++;
    }
    if(n != 1) sum+=n, cnt++;
    if(cnt == 1) sum++;
    return sum;
}
int n, co=0 ;
int main() {
    sieve();
    while(cin>>n && n) {
        cout<<"Case "<<++co<<": "<<LCMsum(n)<<endl;
    }
}
