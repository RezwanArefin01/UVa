#include <bits/stdc++.h>
using namespace std;

long long MOD;
struct Matrix {
    vector< vector<long long> > mat; int row, col;
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
        for(int k = 0; k < col; k++)
            ans.mat[i][j] += ((a.mat[i][k]%MOD) * (b.mat[k][j] % MOD))%MOD ;
    return ans;
}
Matrix matPow(Matrix base, int p) {
    int n = base.row;
    Matrix ans(n,n);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) ans.mat[i][j] = (i==j);
    while(p) {
        if(p & 1) ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    } return ans;
}
long long Fib(int n) {
    Matrix a(2,2); a.mat[0][0] = 1, a.mat[0][1] = 1;
    a.mat[1][0] = 1, a.mat[1][1] = 0;
    return matPow(a,n).mat[0][1];
}
int main() {
    int n,m; while(cin>>n>>m) {
        MOD = 1000000009;
        cout<<Fib(n) % MOD<<endl;
    }
}
