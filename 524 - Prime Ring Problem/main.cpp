#include<bits/stdc++.h>
using namespace std;

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
int N, co = 0, ans[20] = {1};
bool visit[20];
bool isPrime(int a){
    for (int n : prime)
        if (n == a) return true;
    return false;
}
void search(int L) {
    if(L==N) {
        if(!isPrime(ans[N-1] + 1)) return;
        printf("1");
        for(int i=1; i<N; i++) printf(" %d", ans[i]);
        puts("");
    }
    for(int i=2; i<=N; i++) {
        if(visit[i]) continue;
        if(isPrime(i + ans[L-1])) {
            visit[i] = 1;
            ans[L] = i;
            search(L+1);
            visit[i] = 0;
        }
    }

}
int main() {
    while(scanf("%d", &N) != EOF) {
        if(co++) puts("");
        printf("Case %d:\n", co);
        if(N == 1) puts("1");
        else if(!(N%2)){ memset(visit, false, sizeof visit);search(1);}
    }
}
