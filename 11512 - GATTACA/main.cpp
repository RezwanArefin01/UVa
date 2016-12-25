#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define MAX_N 1001
char T[MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];

char P[MAX_N];
int m;

int Phi[MAX_N];
int PLCP[MAX_N];
int LCP[MAX_N];

void countingSort(int k) {
  int i, sum, maxi = max(300, n);
  memset(c, 0, sizeof c);
  for (i = 0; i < n; i++)
    c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for (i = 0; i < n; i++)
    tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
  for (i = 0; i < n; i++)
    SA[i] = tempSA[i];
}

void constract_SA() {
  int i, k, r;
  for (i = 0; i < n; i++) RA[i] = T[i];
  for (i = 0; i < n; i++) SA[i] = i;
  for (k = 1; k < n; k <<= 1) {
    countingSort(k);
    countingSort(0);
    tempRA[SA[0]] = r = 0;
    for (i = 1; i < n; i++)
      tempRA[SA[i]] =
      (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; i++)
      RA[i] = tempRA[i];
    if (RA[SA[n-1]] == n-1) break;
} }

void computeLCP() {
  int i, L;
  Phi[SA[0]] = -1;
  for (i = 1; i < n; i++)
    Phi[SA[i]] = SA[i-1];
  for (i = L = 0; i < n; i++) {
    if (Phi[i] == -1) { PLCP[i] = 0; continue; }
    while (T[i + L] == T[Phi[i] + L]) L++;
    PLCP[i] = L;
    L = max(L-1, 0);
  }
  for (i = 0; i < n; i++)
    LCP[i] = PLCP[SA[i]];
}
void prefix(int *pi) {
    int i=0, j=-1; pi[0] = -1;
    while(i < m) {
        while(j >= 0 && P[i] != P[j]) j = pi[j];
        pi[++i] = ++j;
    }
}
int KMP() {
    int *pi = new int[n+1], i=0 ,j=0;;
    prefix(pi); int Count = 0;
    while(i < n) {
        while(j >=0 && T[i] != P[j]) j = pi[j];
        i++, j++;
        if(j == m) Count++;
    } return Count;
}
int main() {
    int t; cin>>t; getchar(); while(t--) {
        n = (int)strlen(gets(T));
        T[n++] = '$';
        constract_SA();
        computeLCP(); int Max = 0, Maxi = -1;
        for(int i=0; i<n;i++) {
            if(LCP[i] > Max) Max = LCP[i], Maxi = i;
        }
        if(Maxi > -1) {
            strncpy(P, T + SA[Maxi], LCP[Maxi]);
			P[LCP[Maxi]] = '\0';
            m = strlen(P);
            int ans = KMP();
            printf("%s %d\n", P, ans);
        }else puts("No repetitions found!");
    }
}
