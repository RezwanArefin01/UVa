#include<bits/stdc++.h>
using namespace std;

int main() {
    int s,n,a;
    while(cin>>s  && s!= -1) {
        for(n = (int)sqrt(2*s); n >0 ; n--) {
            if((a = 2*s + n - n*n) % (2*n) == 0) {
                a /= (2*n); break;
            }
        }
        printf("%d = %d + ... + %d\n", s, a, a + n - 1);
    }
}
