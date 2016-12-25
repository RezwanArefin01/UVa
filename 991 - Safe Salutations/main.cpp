#include <bits/stdc++.h>
using namespace std;
int main() {
    int f[11] = {1,1,2,5,14,42,132,429,1430,4862,16796}, i, j;
    int n, flag = 0;
    while(scanf("%d", &n) == 1) {
        if(flag)
            puts("");
        flag = 1;
        printf("%d\n", f[n]);
    }
    return 0;
}
