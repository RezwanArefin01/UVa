#include <bits/stdc++.h>
char sieve[500000];
int dpCount[1000000];
char isPrime(int n){
    if (n == 2) return 1;
    else if (! (n % 2)) return 0;
    else return sieve[(n-1)/2];
}
int digitSum(int a){
    static char tempStr[10];
    static int len, sum = 0; int i;
    sprintf(tempStr,"%d",a);
    len = strlen(tempStr);
    for (i = 0; i < len; i++){
        sum += (tempStr[i] - '0');
    }
    return sum;
}

void init(){
    int i, cur;
    memset(sieve,1,sizeof(sieve));
    memset(dpCount,0,sizeof(dpCount)); sieve[0] = 0;
    for (i = 3; i <= 1001; i+=2){
        if (sieve[(i-1)/2]){
            cur = 3*i;
            while (cur < 1000000){
                sieve[(cur-1)/2] = 0;
                cur = cur + i + i;
            }
        }
    }
    dpCount[0] = 0;
    dpCount[1] = 0;
    dpCount[2] = 1;
    for (i = 3; i < 1000000; i++){
        if (isPrime(i) && isPrime( digitSum(i) ))
            dpCount[i] = dpCount[i-1] + 1;
        else dpCount[i] = dpCount[i-1];
    }
}

int main(){
    int N, i, first, last;  init();
    scanf("%d",&N);
    for (i = 0; i < N; i++){
        scanf("%d %d",&first,&last);
        printf("%d\n",dpCount[last]-dpCount[first-1]);
    }
    return 0;
}
