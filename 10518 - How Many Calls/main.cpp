#include<bits/stdc++.h>
using namespace std;
long long n,MOD;
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
Matrix base(3,3);
int main() { int co = 0;
    base.mat[0][0] = base.mat[0][1] = base.mat[0][2] = base.mat[1][0] = base.mat[2][2] = 1;
    while(cin>>n>>MOD && (n||MOD)) {
        int Ans;
        if(n <= 1) Ans = 1;
        else {
            Matrix ans = matPow(base, n-1);
            Ans = (ans.mat[0][0] %MOD + ans.mat[0][1] %MOD + ans.mat[0][2] %MOD) %MOD;
        } cout<<"Case "<<++co<<": "<<n<<" " <<MOD<<" " <<Ans<<endl;
    }
}
