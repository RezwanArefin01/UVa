#include <algorithm>
#include <cstdio>
using namespace std;
int n, A[101][101], maxSubRect, subRect;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    scanf("%d", &A[i][j]);
    if (j > 0) A[i][j] += A[i][j - 1];
  }
  maxSubRect = -127*100*100;
  for (int l = 0; l < n; l++) for (int r = l; r < n; r++) {
    subRect = 0;
    for (int row = 0; row < n; row++) {
      if (l > 0) subRect += A[row][r] - A[row][l - 1];
      else       subRect += A[row][r];

      if (subRect < 0) subRect = 0;
      maxSubRect = max(maxSubRect, subRect);
  } }

  printf("%d\n", maxSubRect);
  return 0;
}
