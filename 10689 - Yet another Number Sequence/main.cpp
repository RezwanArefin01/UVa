#include<bits/stdc++.h>
using namespace std;
long long a,b,n,MOD;
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
    Matrix base(2,2);
    base.mat[0][0] = 1, base.mat[0][1] = 1;
    base.mat[1][0] = 1, base.mat[1][1] = 0;
    Matrix F(2,1); F.mat[0][0] = b, F.mat[1][0] = a;
    if(!n) return a%MOD;
    if(n == 1) return b%MOD;
    return matMul(matPow(base, n-1), F).mat[0][0]%MOD;
}
int main() {
    int t; cin>>t; while(t--) {
        int m;
        cin>>a>>b>>n>>m; MOD = 1;
        for(int i=0; i<m; i++) MOD*=10;
        cout<<f(n)<<endl;
    }
}
