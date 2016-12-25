#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define maxN 1000001
using namespace std;
bool isP[maxN];
vector<int> prime;
int num[120];
void Sieve() {
    Fill(isP, true);
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);
}

int main() { Sieve();
    int Case, n, m, low, up;
    for (scanf("%d", &Case); Case--; ) {
        scanf("%d %d", &n, &m);
        Fill(num, 0);
        low = int(lower_bound(all(prime), n) - prime.begin());
        up = int(upper_bound(all(prime), m) - prime.begin());
        int Max = 0, idx = 0, Count = 0;
        for (int i=low+1; i<up; i++) {
            int tmp = prime[i] - prime[i-1];
            if (++num[tmp]>Max) {
                Max = num[tmp];
                idx = tmp;
            }
        }
        FOR (i, 1, 114)
            if (num[i]==Max) {
                if (++Count>1) break;
            }
        if (Count>1 || Max==0) puts("No jumping champion");
        else printf("The jumping champion is %d\n", idx);
    }
}
