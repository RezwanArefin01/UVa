#include<bits/stdc++.h>
using namespace std;
long long d,n,MOD;
struct Matrix {
    vector< vector<long long> > mat; long long row, col;
    Matrix() {}
    Matrix(long long _row, long long _col) {
        row = _row, col = _col;
        mat.resize(row);
        for(long long i=0; i<row; i++) mat[i].resize(col);
    }
};
Matrix matMul(Matrix a, Matrix b) {
    long long row = a.row, col = b.col;
    Matrix ans(row, col);
    for(long long i=0; i < row; i++) for(long long j=0; j < col; j++)
        for(long long k = 0; k < a.col; k++)
            ans.mat[i][j] = (ans.mat[i][j]%MOD + (a.mat[i][k]%MOD * b.mat[k][j]%MOD)%MOD)%MOD;
    return ans;
}
Matrix matPow(Matrix base, long long p) {
    long long n = base.row;
    Matrix ans(n,n);
    for(long long i=0; i<n; i++) for(long long j=0; j<n; j++) ans.mat[i][j] = (i==j);
    while(p) {
        if(p & 1) ans = matMul(ans, base);
        base = matMul(base, base);
        p >>= 1;
    } return ans;
}
long long f(long long n) {
    Matrix base(d,d);
    for(long long i=0; i<d; i++) cin>>base.mat[0][i];
    for(long long i=1; i<d; i++) for(long long j = 0; j<d; j++) base.mat[i][j] = (i == j+1);
    Matrix F(d,1); for(long long i=d-1; i>=0; i--) cin>>F.mat[i][0];
    return matMul(matPow(base, n-d), F).mat[0][0];
}
int main() {
    while(cin>>d>>n>>MOD && (d||n||MOD)) {
        cout<<f(n)%MOD<<endl;
    }
    return 0;
}
