#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
int n, t; ll q, d;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n == 0) {
            puts("10");
            continue;
        } else if (n < 10) {
            printf("%d\n", n);
            continue;
        }
        d = (q = 0) + 1;
        for (int i = 9; i > 1; --i)
            while (n % i == 0) {
                n /= i;
                q += i * d;
                d *= 10;
            }
        if (n == 1) printf("%lld\n", q);
        else puts("-1");
    }
    return 0;
}
