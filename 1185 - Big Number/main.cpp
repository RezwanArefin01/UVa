#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000001
int digits[SIZE];

int main(){
    digits[0] = 0;
    double d = 0;
    for(int k = 1; k < SIZE; k++){
        d += log10(k);
        digits[k] = (int)d;
    }
    int test, n;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &n);
        printf("%d\n", digits[n]+1);
    }
	return 0;
}
