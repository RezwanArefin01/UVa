#include<bits/stdc++.h>
using namespace std;
#define iii pair<int,pair<int,int>>
struct Job{
    long long int s, t;
    int sn;
};
bool callback(const Job & a, const Job & b){
    long long int  x = a.s* b.t;
    long long int y = a.t*b.s;
    if(x != y) return x > y;
    return  a.sn < b.sn;
}
int main(){
    int N, test;
    Job A[1009];
    scanf("%d",  &test);
    while(test--){
        scanf("%d", &N);
        for(int i = 1; i <= N; i++){
            scanf("%lld %lld", &A[i].t, &A[i].s);
            A[i].sn = i;
        }
        sort(A + 1,A + N + 1, callback);
        for(int i = 1; i <N; i++)
            printf("%d ", A[i].sn);
        printf("%d\n", A[N].sn);
        if(test) puts("");
    }
	return 0;
}
