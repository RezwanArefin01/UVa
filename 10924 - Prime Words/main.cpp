#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<10000010> bs;
ll _sieve_size;
void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.reset();
    bs.flip();
    bs.set(0, false);
    bs.set(1, true);
    for (ll i = 2; i <= _sieve_size; i++) if (bs.test((size_t)i)) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs.set((size_t)j, false);
    }
}
bool isPrime(ll N){return bs.test(N);}
int main()
{
    sieve(2000);
   char s[21];
    while(scanf("%s",s) == 1){
        int L = strlen(s),n = 0;
        for(int i = 0;i < L;++i)
            n += s[i] >= 'a' && s[i] <= 'z'? s[i] - 'a' + 1 : s[i] - 'A' + 27;
        puts(isPrime(n)? "It is a prime word." : "It is not a prime word.");
    }
    return 0;
}
