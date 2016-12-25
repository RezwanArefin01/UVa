#include<bits/stdc++.h>
using namespace std;
#define maxN 31632
bool isP[maxN];
vector<int> prime;

void Sieve() {
    memset(isP,true,sizeof(maxN));
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;
    prime.push_back(2);
    for (int i=1; i<maxN; i+=2)
        if (isP[i]) prime.push_back(i);
}

bool isPrime(int n) {
    if (n<maxN) return isP[n];
    int nn = (int)sqrt(n);
    for (int i=0; i<prime.size() && prime[i]<=nn; i++)
        if (n%prime[i]==0) return false;
    return true;
}
long long Bigmod(long long b,long long p, long long m) {
    b%=m;
    long long ans=1;
    while(p)
    {
        if(p&1) ans = (ans*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return ans;
}
int main() {
    Sieve();
    long long a,p;
    while(cin>>p>>a && (a||p)) {
        bool f;
        if (isPrime(a)) f = false;
        else f = (Bigmod(a,p,p) == a);
        if (f) puts("yes");
        else puts("no");
    }
    return 0;
}
