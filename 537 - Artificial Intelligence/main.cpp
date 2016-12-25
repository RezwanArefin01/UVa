#include<bits/stdc++.h>
using namespace std;
string line;
double get(int i) {
    double ret = 0.0;
    while(isdigit(line[i])) {
        ret = 10*ret + line[i] - '0';
        i++;
    } if(line[i] == '.') {
        double j = 10; i++; while(isdigit(line[i])) {
            ret += ((double)(line[i] - '0') / j );
            j*=10;
            i++;
        }
    }
    if(line[i] == 'm') ret /= 1000;
    if(line[i] == 'k') ret *= 1000;
    if(line[i] == 'M') ret *= 1000000;
    return ret;
}
int main() {
    int t, co=0; cin>>t; getline(cin, line); while(t--) {
        getline(cin, line);
        double U=0,P=0,I=0;
        for(int i=0; line[i+1]; i++) {
            if(line[i] == 'U' && line[i+1] == '=') U = get(i+2);
            if(line[i] == 'P' && line[i+1] == '=') P = get(i+2);
            if(line[i] == 'I' && line[i+1] == '=') I = get(i+2);
        } cout<<"Problem #"<<++co<<endl;
        cout<<fixed<<setprecision(2);
        if(U && P) cout<<"I="<<P/U<<"A\n";
        else if(U && I) cout<<"P="<<U*I<<"W\n";
        else cout<<"U="<<P/I<<"V\n";
        puts("");
    }
}
