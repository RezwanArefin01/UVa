#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int p,q;
struct Matrix {
    vector< vector<ll> > mat; int row, col;
    Matrix() {}
    Matrix(int _row, int _col) {
        row = _row, col = _col;
        mat.resize(row);
        for(int i=0; i<row; i++) mat[i].resize(col);
    }
};
Matrix matMul(Matrix a, Matrix b) {
    int row = a.row, col = b.col;
    Matrix ans(row, col);
    for(int i=0; i < row; i++) for(int j=0; j < col; j++)
        for(int k = 0; k < a.col; k++)
            ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];
    return ans;
}
Matrix matPow(Matrix base, ll p) {
    int n = base.row;
    Matrix ans(n,n);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) ans.mat[i][j] = (i==j);
    while(p) {
        if(p & 1) ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    } return ans;
}
ll f(ll n) {
    if(!n) return 2;
    if(n == 1) return p;
    Matrix base(2,2); base.mat[0][0] = p, base.mat[0][1] = -q, base.mat[1][0] = 1;
    base = matPow(base, n-1);
    ll ans = base.mat[0][0] * p + base.mat[0][1] * 2;
    return ans;
}
int main() { int n;
    while(scanf("%d %d %d", &p, &q, &n) == 3) {
        cout<<f(n)<<endl;
    }
}
