#include<stdio.h>
#include<string.h>
#define MaxL 1000005
int KMP_init(char *A) {
	int i, j; int P[MaxL];
	P[0] = -1, i = 1, j = -1;
	while(A[i]) {
		while(j >= 0 && A[j+1] != A[i])	j = P[j];
		if(A[j+1] == A[i])	++j;
		P[i++] = j;
	}
	return j;
}
int main() {
	char s[MaxL];
	while(~scanf("%s", s) && strcmp(s,".") != 0) {
		int l = strlen(s), t = KMP_init(s);
		printf("%d\n", l/(l-t-1));
	}
    return 0;
}
