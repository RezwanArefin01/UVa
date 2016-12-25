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
int sumDiv(int N) { int PF_idx = 0, PF = prime[PF_idx], ans = 1;
    while (PF * PF <= N) {
        int power = 0;
        while (N % PF == 0) { N /= PF; power++; }
        ans *= ((int)pow((double)PF, power + 1.0) - 1) / (PF - 1);
        PF = prime[++PF_idx];
    } if (N != 1) ans *= ((int)pow((double)N, 2.0) - 1) / (N - 1);
    return ans;
}
int co = 0;
int main() {
    sieve();
    vector<int> n_d(1001, -1);
    n_d[1] = 1;
    for(int i = 2; i<=1000; i++) {
        int x = sumDiv(i);
        if(x<=1000) n_d[x] = i;
    }
    int n;
    while(cin>>n && n) cout<<"Case "<<++co<<": "<<n_d[n]<<endl;
}
