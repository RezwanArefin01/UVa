#include<bits/stdc++.h>
using namespace std;
string line;
bool can(){
    for(int i=0; i<11; i++)
        if(line[i] == 'o' && line[i+1] == 'o') return true;
    return false;
}
int solve(int q) {
    if(!can()) return q;
    int Min = q, bef, aft;
    for(int i=0; i<11; i++) {
        if(line[i] == 'o' && line[i+1] == 'o') {
            bef = aft = q;
            if(i-1 >=0 && line[i-1] == '-') {
                line[i-1] = 'o', line[i+1] = line[i] = '-',
                bef = solve(q-1);
                line[i-1] = '-', line[i+1] = line[i] = 'o';
            }
            if(i+2<12 && line[i+2] == '-') {
                line[i] = line[i+1] = '-', line[i+2] = 'o';
                aft = solve(q-1);
                line[i] = line[i+1] = 'o', line[i+2] = '-';
            } Min = min(Min, min(aft, bef));
        }
    } return Min;
}
int main() {
    int t; cin>>t; while(t--) {
        cin>>line;
        int p = 0; for(auto c : line) if(c == 'o') p++;
        cout<<solve(p)<<endl;
    }
}
