#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000009
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
            ans.mat[i][j] =  (ans.mat[i][j]%MOD + a.mat[i][k]%MOD * b.mat[k][j]%MOD) %MOD;
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
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(n == 3) return 2;
    Matrix base(3,3); base.mat[0][0] = base.mat[0][1] = base.mat[0][2] = base.mat[1][0] = base.mat[2][1] = 1;
    base = matPow(base, n-3);
    return ((base.mat[0][0]*2)%MOD + base.mat[0][1] %MOD)%MOD;

}
int main() { ll n;
    while(cin>>n && n) {
        cout<<f(n)<<endl;
    }
}
