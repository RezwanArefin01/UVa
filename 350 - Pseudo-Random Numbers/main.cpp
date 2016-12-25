#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int caseNo = 1, Z, I, M, L;

int f(int x) { return (Z * x + I) % M; }
int floydCycleFinding(int x0) {
  int tortoise = f(x0), hare = f(tortoise);
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
  int mu = 0; hare = x0;
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++; }
  int lambda = 1; hare = f(tortoise);
  while (tortoise != hare) { hare = f(hare); lambda++; }
  return  lambda;
}

int main() {
  while (scanf("%d %d %d %d", &Z, &I, &M, &L), (Z || I || M || L)) {
    int result = floydCycleFinding(L);
    printf("Case %d: %d\n", caseNo++, result);
  }
  return 0;
}
