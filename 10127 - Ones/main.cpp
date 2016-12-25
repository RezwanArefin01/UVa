#include<bits/stdc++.h>
using namespace std;


int main() {
    int n; while(cin>>n) {
        int one = 1, k; long long N = 1;
        while(1) {
            if(N < n) {
                N = N*10 + 1;
                ++one;
            } k = N % n;
            if(k != 0) N = k;
            else break;
        }
        cout<<one<<endl;
    }
}
